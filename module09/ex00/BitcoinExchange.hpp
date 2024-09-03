/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:15:51 by vshchuki          #+#    #+#             */
/*   Updated: 2024/09/03 14:58:08 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <regex>

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
		static const std::regex					dbPattern;
		std::string								inputFilename;
		std::ifstream							inputStream;
		static const std::regex					inputPattern;

		void									loadFile(std::ifstream& stream, std::string dataFilename);
		bool									matchPattern(std::string str, std::regex pattern);
		void									parseStream(std::ifstream& stream, std::string delimiter);
		ssize_t									binarySearchRate(std::string dateStr);
		void									convert(std::ifstream& stream, std::string delimiter);
		std::tuple<std::string, std::string>	splitStrToTuple(std::string str, std::string delimiter);
		time_t									convertToEpoch(const std::string& dateString);
		std::string								trimTrailingZeros(std::string floatStr);

	public:
		BitcoinExchange();
		BitcoinExchange(const char*);
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();


		class Error : public std::exception
		{
			private:
				std::string message;

			public:
				Error();
				Error(const std::string& message);
				Error(const Error& other);
				Error& operator=(const Error& other);
				~Error();

				std::string getMessage() const;
		};

		void									run();
		static void								log(std::string message, LogType type = DEFAULT);

};
