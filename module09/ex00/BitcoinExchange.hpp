/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:15:51 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/08 02:01:26 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

// Text color macros
#define			TEXT_GREEN "\033[32m"
#define			TEXT_BLUE "\033[34m"
#define			TEXT_WHITE "\033[37m"

// Background color macros
#define			BG_RED "\033[41m"

// Reset macros
#define			RESET "\033[0m"

#define			EXIT_SUCCESS 0
#define			EXIT_FAILURE 1

enum LogType
{
	DEFAULT,
	ERROR,
	INFO,
	SUCCESS
};

class BitcoinExchange
{
	private:
		static const std::string 				dbFilename;
		std::ifstream							dbStream;
		std::deque<time_t>						dbDataDates;
		std::deque<float>						dbDataRates;
		std::string								inputFilename;
		std::ifstream							inputStream;

		void									loadFile(std::ifstream& stream, std::string dataFilename);
		std::tuple<std::string, std::string>	splitStrToTuple(std::string str, std::string delimiter);
		time_t									convertToEpoch(const std::string& dateString);
		void									parseStream(std::ifstream& stream, std::string delimiter);
		ssize_t									binarySearchRate(std::string dateStr);
		void									convert(std::ifstream& stream, std::string delimiter);
		std::string								trimTrailingZeros(std::string floatStr);

	public:
		BitcoinExchange();
		BitcoinExchange(const char*);
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();


		class ExchangeError : public std::exception
		{
			private:
				std::string message;

			public:
				ExchangeError(const std::string& message);
				std::string getMessage() const;
		};

		static void								log(std::string message, LogType type = DEFAULT);

};
