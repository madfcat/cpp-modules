/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:15:48 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/08 03:19:06 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Orthodox Canonical Form */

const std::string BitcoinExchange::dbFilename = "data.csv";

BitcoinExchange::BitcoinExchange()
{
	log("BitcoinExchange default constructor called", INFO);
}

BitcoinExchange::BitcoinExchange(const char *inputFilename) : inputFilename(inputFilename)
{
	log("BitcoinExchange constructor called", INFO);
	loadFile(this->dbStream, this->dbFilename);
	loadFile(this->inputStream, this->inputFilename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : dbDataDates(other.dbDataDates),
																dbDataRates(other.dbDataRates)
{
	log("BitcoinExchange copy constructor called", INFO);
	this->inputFilename = other.inputFilename;
	loadFile(this->dbStream, this->dbFilename);
	loadFile(this->inputStream, this->inputFilename);
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	log("BitcoinExchange assignment operator called", INFO);
	if (this != &other)
	{
		this->inputFilename = other.inputFilename;
		this->dbDataDates = other.dbDataDates;
		this->dbDataRates = other.dbDataRates;
		this->dbStream.close();
		this->inputStream.close();
		loadFile(this->dbStream, this->dbFilename);
		loadFile(this->inputStream, this->inputFilename);
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	log("BitcoinExchange default destructor called", INFO);
	if (this->dbStream.is_open())
		this->dbStream.close();
	if (this->inputStream.is_open())
		this->inputStream.close();
}

/* Methods */

void BitcoinExchange::loadFile(std::ifstream& stream, std::string dbFilename)
{
	stream.open(dbFilename);
	if (!stream.is_open())
		throw Error("File can not be opened: " + dbFilename);
}

void BitcoinExchange::parseStream(std::ifstream& stream, std::string delimiter)
{
	std::string line;

	getline(stream, line);
	while (getline(stream, line))
	{
		float value;
		time_t epochDate;

		try
		{
			auto [dateStr, valueStr] = splitStrToTuple(line, delimiter);
			if ((value = std::stof(valueStr)) < 0)
				throw BitcoinExchange::Error("Not a positive number.");
			epochDate = convertToEpoch(dateStr);
			this->dbDataDates.push_back(epochDate);
			this->dbDataRates.push_back(value);
		}
		catch (const BitcoinExchange::Error& e)
		{
			log(e.getMessage(), ERROR);
		}
	}
}

ssize_t BitcoinExchange::binarySearchRate(std::string dateStr)
{

	ssize_t start = 0;
	ssize_t end = dbDataDates.size() - 1;

	time_t epochDate = convertToEpoch(dateStr);

	if (end == -1)
		throw BitcoinExchange::Error("No matching rate for the date: " + dateStr);

	ssize_t curr = start + (end - start) / 2;
	while (start != curr)
	{
		if (epochDate == this->dbDataDates[curr])
			return curr;

		if (epochDate > this->dbDataDates[curr])
		{
			start = curr;
		}
		else
		{
			end = curr;
		}
		curr = start + (end - start) / 2;
	}
	if (curr == 0 && epochDate < dbDataDates[curr])
		throw BitcoinExchange::Error("No matching rate for the date: " + dateStr);
	return curr;
}

void BitcoinExchange::convert(std::ifstream& stream, std::string delimiter)
{
	std::string line;
	getline(stream, line);
	while (getline(stream, line))
	{
		float value;

		try
		{
			auto [dateStr, valueStr] = splitStrToTuple(line, delimiter);
			if ((value = std::stof(valueStr)) < 0)
				throw BitcoinExchange::Error("Not a positive number.");
			if (value > 1000)
				throw BitcoinExchange::Error("Too large a number.");

			ssize_t curr = binarySearchRate(dateStr);

			log(dateStr + " => " + trimTrailingZeros(std::to_string(value)) + 
				" = " + trimTrailingZeros(std::to_string(dbDataRates[curr] * value)), SUCCESS);
		}
		catch (const BitcoinExchange::Error& e)
		{
			log(e.getMessage(), ERROR);
		}
	}
}

void BitcoinExchange::run()
{
	parseStream(this->dbStream, ",");
	log("Parsed dbStream", INFO);
	convert(this->inputStream, " | ");
}

std::tuple<std::string, std::string> BitcoinExchange::splitStrToTuple(std::string str, std::string delimiter)
{
	size_t delimiterPos = str.find(delimiter);
	if (delimiterPos == std::string::npos || delimiterPos == 0 || delimiterPos == str.length() - 1)
		throw BitcoinExchange::Error("Bad input => " + str);

	return {str.substr(0, str.find(delimiter)), str.substr(str.find(delimiter) + delimiter.length())};
}

time_t BitcoinExchange::convertToEpoch(const std::string& dateString)
{
	std::tm tm = {};
	std::istringstream ss(dateString);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail()) {
		throw BitcoinExchange::Error("Failed to parse date: " + dateString);
	}

	// Set the time to midnight
	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;
	tm.tm_isdst = -1;  // Not considering daylight saving time

	time_t timeSinceEpoch = std::mktime(&tm);
	if (timeSinceEpoch == -1) {
		throw BitcoinExchange::Error("Failed to convert date to time_t: " + dateString);
	}

	return timeSinceEpoch;
}

std::string BitcoinExchange::trimTrailingZeros(std::string floatStr) {
	size_t dotPos = floatStr.find(".");
	if (dotPos == std::string::npos) {
		return floatStr;
	}

	size_t lastNonZeroPos = floatStr.find_last_not_of('0');
	if (lastNonZeroPos == std::string::npos || lastNonZeroPos < dotPos) {
		return floatStr.substr(0, dotPos);
	}

	if (lastNonZeroPos == dotPos) {
		lastNonZeroPos--;
	}

	return floatStr.substr(0, lastNonZeroPos + 1);
}

void BitcoinExchange::log(std::string message, LogType type)
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

/* Error */

std::string BitcoinExchange::Error::getMessage() const
{
	return this->message;
}

BitcoinExchange::Error::Error(const std::string& message)
{
	this->message = message;
}
