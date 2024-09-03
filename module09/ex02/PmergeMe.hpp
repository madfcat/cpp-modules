/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:53:26 by vshchuki          #+#    #+#             */
/*   Updated: 2024/09/04 02:47:18 by vshchuki         ###   ########.fr       */
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
#include <algorithm>
#include <cmath>

// Rec value macros
#define 		EMPTY 0
#define 		NOT_INIT -1

// Text color macros
#define			TEXT_GREEN "\033[32m"
#define			TEXT_YELLOW "\033[33m"
#define			TEXT_BLUE "\033[34m"
#define			TEXT_WHITE "\033[37m"

// Background color macros
#define			BG_RED "\033[41m"

// Reset macros
#define			RESET "\033[0m"

// Exit macros
#define			EXIT_SUCCESS 0
#define			EXIT_FAILURE 1

enum LogType
{
	DEFAULT,
	ERROR,
	INFO,
	SUCCESS,
	DEBUG
};

enum ContType
{
	VECTOR,
	LIST
};


class PmergeMe
{
	public:
		class Rec
		{
			public:
				int mainChain;
				std::pair<Rec*, Rec*> pair;

				Rec();
				Rec(int value);
				Rec(int value, Rec* first, Rec* second);
				Rec(const Rec& other);
				Rec& operator=(const Rec& other);
				~Rec();
		};

	private:
		std::vector<std::string>						argv;
		std::vector<PmergeMe::Rec>						numVec;
		long long										vecUsecs = 0;
		std::list<PmergeMe::Rec>						numList;
		long long										listUsecs = 0;
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
				Error();
				Error(const std::string& message);
				Error(const Error& other);
				Error& operator=(const Error& other);
				~Error();

				std::string getMessage() const;
		};

		template <typename T>
		void							initArr(const int argc, const char* argv[], T& container, long long& usecs);

		/* Vector */
		void							swapInit(std::vector<PmergeMe::Rec>& arr);
		std::vector<PmergeMe::Rec>		createInitPairs(std::vector<PmergeMe::Rec>& arr);
		void							insertAs(unsigned long& lastT, unsigned long& addAFromIndex,
											std::vector<PmergeMe::Rec>& newArr, std::vector<PmergeMe::Rec>& insertionArr);
		void							insertBs(unsigned long& lastT, unsigned long& addAFromIndex,
											std::vector<PmergeMe::Rec>& newArr, std::vector<PmergeMe::Rec>& insertionArr);
		void							insertSort(std::vector<PmergeMe::Rec>& newArr, std::vector<PmergeMe::Rec>& insertionArr);
		std::vector<PmergeMe::Rec>		sortVec(std::vector<PmergeMe::Rec>& arr);
		std::vector<PmergeMe::Rec>		executeVec();

		/* List */
		void							swapInit(std::list<PmergeMe::Rec>& arr);
		std::list<PmergeMe::Rec>		createInitPairs(std::list<PmergeMe::Rec>& arr);
		void							insertAs(unsigned long& lastT, unsigned long& addAFromIndex,
											std::list<PmergeMe::Rec>& newArr, std::list<PmergeMe::Rec>& insertionArr);
		void							insertBs(unsigned long& lastT, unsigned long& addAFromIndex,
											std::list<PmergeMe::Rec>& newArr, std::list<PmergeMe::Rec>& insertionArr);
		void							insertSort(std::list<PmergeMe::Rec>& newArr, std::list<PmergeMe::Rec>& insertionArr);
		template <typename T>
		typename std::list<T>::iterator getElementAtIndex(std::list<T>& lst, size_t index);
		std::list<PmergeMe::Rec>		sortList(std::list<PmergeMe::Rec>& arr);
		std::list<PmergeMe::Rec>		executeList();

		template<typename T>
		bool							checkSorted(T& container);
		void							run();

		/* Logging */
		template <typename T>
		void							printTime(T& container, ContType type, long long usecs) const;
		template <typename T>
		std::string						createSeq(T& container) const;
		void							printArr(std::list<PmergeMe::Rec>& arr, std::string msg = "Base Pair");
		void							printArr(std::vector<PmergeMe::Rec>& arr, std::string msg = "Base Pair");
		void							printEl(PmergeMe::Rec& el, std::string msg = "Base Pair");
		static void						log(std::string message, LogType type = DEFAULT);
};

std::ostream& operator<<(std::ostream& os, const PmergeMe::Rec& rec);
