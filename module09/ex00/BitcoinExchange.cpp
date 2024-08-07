/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:15:48 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/07 17:38:08 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::dbFilename = "data.csv";

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const char *inputFilename) : inputFilename(inputFilename)
{
	loadFile(this->dbData, this->dbFilename);
	loadFile(this->inputData, this->inputFilename);
	std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->inputFilename = other.inputFilename;
	loadFile(this->dbData, this->dbFilename);
	loadFile(this->inputData, this->inputFilename);
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->inputFilename = other.inputFilename;
		this->dbData.close();
		this->inputData.close();
		loadFile(this->dbData, this->dbFilename);
		loadFile(this->inputData, this->inputFilename);
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange default destructor called" << std::endl;
	if (this->dbData.is_open())
		this->dbData.close();
	if (this->inputData.is_open())
		this->inputData.close();
}

void BitcoinExchange::loadFile(std::ifstream& stream, std::string dbFilename)
{
	stream.open(dbFilename);
	if (!stream.is_open())
		throw ExchangeError("File can not be opened: " + dbFilename);
}

std::string BitcoinExchange::ExchangeError::getMessage() const
{
	return this->message;
}

BitcoinExchange::ExchangeError::ExchangeError(const std::string& message)
{
	this->message = message;
}

void BitcoinExchange::log(std::string message, LogType type = DEFAULT)
{
	switch (type)
	{
		case INFO:
			std::cout << "❕ " << TEXT_BLUE ;
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