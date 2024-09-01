/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:53:26 by vshchuki          #+#    #+#             */
/*   Updated: 2024/09/01 23:18:04 by vshchuki         ###   ########.fr       */
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
#include <algorithm>
#include <variant>
#include <memory>

#define EMPTY_PAIR -1

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

// template<typename T>
// struct ArrStruct
// {
// 	T indices;
// 	T values;
// };

// struct

// using RecPair = std::shared_ptr<std::pair<int, RecPair>>;

struct RecursivePair;
using RecursivePairVariant = std::variant<int, std::pair<int, int>, std::shared_ptr<std::pair<int, RecursivePair>>>;

struct RecursivePair {
    RecursivePairVariant value;

    // Constructor for the base case: pair<int, int>
    // RecursivePair(int num) : value(num) {}

    // Constructor for the base case: pair<int, int>
    RecursivePair(int first, int second) : value(std::make_pair(first, second)) {}

    // Constructor for the recursive case: pair<int, RecursivePair>
    RecursivePair(int first, RecursivePair next)
        : value(std::make_shared<std::pair<int, RecursivePair>>(std::make_pair(first, next))) {}

    // Function to access int
    bool isInt(int& num) const {
        if (std::holds_alternative<int>(value)) {
            num = std::get<int>(value);
            return true;
        }
        return false;
    }

    // Function to access pair<int, int>
    bool isPairIntInt(std::pair<int, int>& pair) const {
        if (std::holds_alternative<std::pair<int, int>>(value)) {
            pair = std::get<std::pair<int, int>>(value);
            return true;
        }
        return false;
    }

    // Function to access pair<int, RecursivePair>
    bool isPairIntRecursivePair(std::pair<int, RecursivePair>& pair) const {
        if (auto sptr = std::get_if<std::shared_ptr<std::pair<int, RecursivePair>>>(&value)) {
            pair = *sptr->get();
            return true;
        }
        return false;
    }
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
		// template <typename T>
		// void						sort(T& arr1, T& arr2);
		// template <typename T, template <typename, typename...> class Container>
		// Container<RecursivePair>	splitInitPairs(T& arr1);
		
		std::vector<RecursivePair>	createInitPairs(std::vector<int>& arr1);
		// std::vector<RecursivePair>	createRecPairs(std::vector<RecursivePair>& arr);
		// void						swapInitSplit(std::vector<RecursivePair>& split);
		void						swapInitSplit(std::vector<RecursivePair>& split);
		
		void						sortVec(std::vector<int>& arr1);

		// void						mergeInsertMainChain(std::vector<RecursivePair>& arr);

		void						execute(ContType);
		void						run();
		static void					log(std::string message, LogType type = DEFAULT);
};

// template void PmergeMe::printInfo(std::vector<int>& container, ContType type, long long usecs) const;
// template void PmergeMe::printInfo(std::list<int>& container, ContType type, long long usecs) const;