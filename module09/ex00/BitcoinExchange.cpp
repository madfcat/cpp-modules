/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:15:48 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/08 00:26:51 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Orthodox Canonical Form */

const std::string BitcoinExchange::dbFilename = "data.csv";

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const char *inputFilename) : inputFilename(inputFilename)
{
	std::cout << "BitcoinExchange constructor called" << std::endl;
	loadFile(this->dbStream, this->dbFilename);
	loadFile(this->inputStream, this->inputFilename);

	parseStream(this->dbStream, this->dbDataDates, this->dbDataRates, ",");
	log("Parsed dbStream", INFO);
	parseStream(this->inputStream, this->inputDataDates, this->inputDataValues, " | ");

	for (size_t i = 0; i < inputDataDates.size(); i++)
	{
		ssize_t curr = binarySearchRate(inputDataDates[i]);
		log("found", INFO);
		log(std::to_string(curr), INFO);
		log(std::to_string(dbDataDates[curr]), INFO);
		log(std::to_string(inputDataDates[i]) + " => " + std::to_string(inputDataValues[i]) + 
			" = " + std::to_string(dbDataRates[curr] * inputDataValues[i]), INFO);
		// log(std::to_string(dbDataRates[curr] * inputDataValues[i]), INFO);
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->inputFilename = other.inputFilename;
	loadFile(this->dbStream, this->dbFilename);
	loadFile(this->inputStream, this->inputFilename);
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->inputFilename = other.inputFilename;
		this->dbStream.close();
		this->inputStream.close();
		loadFile(this->dbStream, this->dbFilename);
		loadFile(this->inputStream, this->inputFilename);
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange default destructor called" << std::endl;
	if (this->dbStream.is_open())
		this->dbStream.close();
	if (this->inputStream.is_open())
		this->inputStream.close();
}

/* methods */

void BitcoinExchange::loadFile(std::ifstream& stream, std::string dbFilename)
{
	stream.open(dbFilename);
	if (!stream.is_open())
		throw ExchangeError("File can not be opened: " + dbFilename);
}

void BitcoinExchange::parseStream(std::ifstream& stream, std::deque<time_t>& dataDates,
									std::deque<float>& dataValues, std::string delimiter)
{
	std::string line;
	bool isRates = delimiter == ",";

	getline(stream, line);
	while (getline(stream, line))
	{
		float value;
		time_t epochDate;

		std::cout << line << std::endl;
		try
		{
			auto [dateStr, valueStr] = splitStrToTuple(line, delimiter);
			// log(valueStr, INFO);
			if ((value = std::stof(valueStr)) < 0 && !isRates)
				throw BitcoinExchange::ExchangeError("Not a positive number.");
			if (value > 1000 && !isRates)
				throw BitcoinExchange::ExchangeError("Too large a number.");
			epochDate = convertToEpoch(dateStr);
			dataDates.push_back(epochDate);
			dataValues.push_back(value);
			log(std::to_string(dataDates.back()), INFO);
			log(std::to_string(dataValues.back()), INFO);
		}
		catch (BitcoinExchange::ExchangeError& e)
		{
			log(e.getMessage(), ERROR);
		}
		// catch (std::out_of_range& e)
		// {
		// 	log("Too large a number.", ERROR);
		// }
	}
}

std::tuple<std::string, std::string> BitcoinExchange::splitStrToTuple(std::string str, std::string delimiter)
{
	size_t delimiterPos = str.find(delimiter);
	if (delimiterPos == std::string::npos || delimiterPos == 0 || delimiterPos == str.length() - 1)
		throw BitcoinExchange::ExchangeError("Bad input => " + str);

	return {str.substr(0, str.find(delimiter)), str.substr(str.find(delimiter) + delimiter.length())};
}

time_t BitcoinExchange::convertToEpoch(const std::string& dateString)
{
	std::tm tm = {};
	std::istringstream ss(dateString);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail()) {
		throw BitcoinExchange::ExchangeError("Failed to parse date: " + dateString);
	}
	// Adjust the month and day to fit the std::tm format (months from 0 to 11 and days from 1 to 31)
	// tm.tm_mon -= 1;  // tm_mon is 0-based
	// tm.tm_mday = 1;  // tm_mday is 1-based, but this is already correct

	// Set the time to midnight
	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;
	tm.tm_isdst = -1;  // Not considering daylight saving time

	// Convert std::tm to time_t
	time_t timeSinceEpoch = std::mktime(&tm);
	if (timeSinceEpoch == -1) {
		throw BitcoinExchange::ExchangeError("Failed to convert date to time_t: " + dateString);
	}

	return timeSinceEpoch;
}

ssize_t BitcoinExchange::binarySearchRate(time_t date)
{

	ssize_t start = 0;
	ssize_t end = dbDataDates.size() - 1;

	if (end == -1)
		return -1;

	ssize_t curr = start + (end - start) / 2;
	while (start != curr)
	{
		if (date == this->dbDataDates[curr])
			return curr;

		if (date > this->dbDataDates[curr])
		{
			start = curr;
		}
		else
		{
			end = curr;
		}
		curr = start + (end - start) / 2;
	}
	return curr;
}

void BitcoinExchange::log(std::string message, LogType type = DEFAULT)
{
	switch (type)
	{
		case INFO:
			std::cout << "ℹ️ " << TEXT_BLUE ;
			break;
		case ERROR:
			std::cout << "🚫 " << BG_RED << TEXT_WHITE ;
			break;
		case SUCCESS:
			std::cout << "✅ " << TEXT_GREEN ;
			break;
		case DEFAULT:
			break;
	}
	std::cout << message << RESET << std::endl;
}

/* ExchangeError */

std::string BitcoinExchange::ExchangeError::getMessage() const
{
	return this->message;
}

BitcoinExchange::ExchangeError::ExchangeError(const std::string& message)
{
	this->message = message;
}
