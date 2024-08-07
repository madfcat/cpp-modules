/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:15:51 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/08 00:20:58 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

// Text color macros
// #define TEXT_BLACK         "\033[30m"
#define TEXT_RED           "\033[31m"
#define TEXT_GREEN         "\033[32m"
#define TEXT_YELLOW        "\033[33m"
#define TEXT_BLUE          "\033[34m"
// #define TEXT_MAGENTA       "\033[35m"
// #define TEXT_CYAN          "\033[36m"
#define TEXT_WHITE         "\033[37m"
// #define TEXT_BRIGHT_YELLOW "\033[0;93m"
// #define TEXT_GREY          "\033[90m"

// Background color macros
// #define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
// #define BG_GREEN   "\033[42m"
// #define BG_YELLOW  "\033[43m"
// #define BG_BLUE    "\033[44m"
// #define BG_MAGENTA "\033[45m"
// #define BG_CYAN    "\033[46m"
// #define BG_WHITE   "\033[47m"

// Text style macros
// #define TEXT_BOLD      "\033[1m"
// #define TEXT_UNDERLINE "\033[4m"
// #define TEXT_BOLD_UNDERLINE "\033[1;4m"

// Reset macros
#define RESET "\033[0m"
// #define RESET_UNDERLINE "\033[24m"
// #define RESET_BOLD "\033[22m"
// #define RESET_BOLD_UNDERLINE "\033[22;24m"
// #define RESET_BG "\033[49m"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

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
		std::deque<float>							dbDataRates;
		std::string								inputFilename;
		std::ifstream							inputStream;
		std::deque<time_t>						inputDataDates;
		std::deque<float>							inputDataValues;

		void									loadFile(std::ifstream& stream, std::string dataFilename);
		std::tuple<std::string, std::string>	splitStrToTuple(std::string str, std::string delimiter);
		time_t									convertToEpoch(const std::string& dateString);
		void									parseStream(std::ifstream& stream, std::deque<time_t>& dataDates,
															std::deque<float>& dataValues, std::string delimiter);
		ssize_t									binarySearchRate(time_t date);
		// convert();

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

		static void								log(std::string message, LogType type);

};
