/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:53:26 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/28 23:43:08 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <chrono>
#include <thread>

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

		enum ContType
		{
			VECTOR,
			LIST
		};

class PmergeMe
{
	private:
		std::vector<std::string>						argv;
		std::vector<int>								numVec;
		long long										vecUsecs;
		std::list<int>									numList;
		long long										listUsecs;
		static const std::map<ContType, std::string>	containerTypes;

	public:
		PmergeMe();
		PmergeMe(const int argc, const char* argv[]);
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();


		class Error : public std::exception
		{
			private:
				std::string message;

			public:
				Error(const std::string& message);
				std::string getMessage() const;
		};

		template <typename T>
		void printTime(T& container, ContType type, long long usecs) const
		{
			log("Time to process a range of " +
				std::to_string(container.size()) + " elements with " +
				"std::" + containerTypes.at(type) + " : " +
				std::to_string(usecs) + " us: ", INFO);
		}

		template <typename T>
		std::string createSeq(T& container) const
		{
			std::ostringstream oss;
			for (auto it = container.begin(); it != container.end(); ++it) {
				if (it != container.begin())
					oss << " ";
				oss << *it;
			}
			return oss.str();
		}

		void						execute(ContType);
		void						run();
		static void					log(std::string message, LogType type = DEFAULT);
};

// template void PmergeMe::printInfo(std::vector<int>& container, ContType type, long long usecs) const;
// template void PmergeMe::printInfo(std::list<int>& container, ContType type, long long usecs) const;