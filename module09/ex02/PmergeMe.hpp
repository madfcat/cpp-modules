/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:53:26 by vshchuki          #+#    #+#             */
/*   Updated: 2024/09/02 15:07:22 by vshchuki         ###   ########.fr       */
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
#include <thread> // remove this
#include <algorithm>
#include <variant>
#include <memory>
#include <cmath>

#define EMPTY 0
#define NOT_INIT -1

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

struct Rec {
	int mainChain;
	std::pair<Rec*, Rec*> pair;

	Rec() : mainChain(NOT_INIT), pair(nullptr, nullptr) {};
	Rec(int value) : mainChain(value), pair(nullptr, nullptr) {}
	Rec(int value, Rec* first, Rec* second) : mainChain(value), pair(first, second) {}
	Rec(const Rec& other) : mainChain(other.mainChain), pair(other.pair.first, other.pair.second) {
		// std::cout << "Rec copied with mainChain: " << mainChain << std::endl;
	}
	Rec& operator=(const Rec& other) {
		if (this != &other) {  // self-assignment check
			mainChain = other.mainChain;
			pair = other.pair;
		}
		return *this;
	}
};


class PmergeMe
{
	private:
		std::vector<std::string>						argv;
		std::vector<Rec>								numVec;
		long long										vecUsecs;
		std::list<Rec>									numList;
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

		void						swapInit(std::vector<Rec>& arr);
		std::vector<Rec>			createInitPairs(std::vector<Rec>& arr);
		// void						createInitPairs(std::vector<Rec>& arr);
		
		std::vector<Rec>			sortVec(std::vector<Rec>& arr);
		// void						mergeInsertMainChain(std::vector<Rec>& arr);

		std::vector<Rec>			execute(ContType);
		void						run();
		void						printArr(std::vector<Rec>& arr, std::string msg = "Base Pair");
		void						printEl(Rec& el, std::string msg = "Base Pair");
		static void					log(std::string message, LogType type = DEFAULT);
};

std::ostream& operator<<(std::ostream& os, const Rec& rec);

// template void PmergeMe::printInfo(std::vector<int>& container, ContType type, long long usecs) const;
// template void PmergeMe::printInfo(std::list<int>& container, ContType type, long long usecs) const;