/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:53:23 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/29 17:28:14 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const std::map<ContType, std::string> PmergeMe::containerTypes = {{VECTOR, "vector"}, {LIST, "list"}};

PmergeMe::PmergeMe()
{
	log("PmergeMe default constructor called", INFO);
}

PmergeMe::PmergeMe(const int argc, const char* argv[])
{
	log("PmergeMe constructor called", INFO);
	this->argv = std::vector<std::string>(argv + 1, argv + argc);
	for (int i = 1; i < argc; i++)
	{
		int newNum = std::stoi(argv[i]);
		if (std::find(this->numVec.begin(), this->numVec.end(), newNum) != std::end(this->numVec))
			throw PmergeMe::Error("This element is not unique: " + std::to_string(newNum));
		if (newNum <= 0)
			throw PmergeMe::Error("Not a positive number: " + std::to_string(newNum));

		this->numVec.push_back(newNum);
		this->numList.push_back(newNum);
	}
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	log("PmergeMe copy constructor called", INFO);
	this->numVec = other.numVec;
	this->numList = other.numList;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	log("PmergeMe assignment operator called", INFO);
	if (this != &other)
	{
		this->numVec = other.numVec;
		this->numList = other.numList;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	log("PmergeMe destructor called", INFO);
}

/* Methods */

template <typename T>
void compareSwap(T& arr1, T& arr2, int aInd)
{
	if (arr1[aInd] < arr1[aInd - 1])
	{
		int temp = arr1[aInd];
		arr1[aInd] = arr1[aInd - 1];
		arr1[aInd - 1] = temp;

		if (arr1 != arr2)
		{
			// int temp1 = arr2[2 * aInd];
			// arr2[2 * aInd] = arr2[aInd];
			// arr2[aInd] = temp1;

			int temp2 = arr2[2 * aInd - 1];
			arr2[2 * aInd - 1] = arr2[2 * (aInd - 1) - 1];
			arr2[2 * (aInd - 1) - 1] = temp2;
		}
	}
}

template <typename T>
T extractMainChain(T& arr)
{
	T mainChain;
	for (size_t i = 1; i < arr.size(); i += 2) {
		mainChain.push_back(arr[i]);
	}
	return mainChain;
}

template <typename T>
void PmergeMe::sort(T& arr1, T& arr2)
{
	std::cout << "---" << std::endl;
	// Sorting

	/*
	1. Divide all numbers in pairs and swap them. Find the larger number in pairs. Sort pairs according to 
	these larger numbers using merge insertion recursively
	The base case is when main chain has only 2 numbers. Return vector with sorted indices.
	Outer function should apply this order to the numbers and its pairs.
	2. 
	
	
	*/

	/* Swap pairs to have a1, a2... as largest in pair*/

	for (unsigned long i = 1; i < arr1.size(); i += 2)
	{
		compareSwap(arr1, arr2, i);
	}
	log("Now swaped: " + createSeq(arr1), INFO);
	log("Now swaped prev: " + createSeq(arr2), INFO);
	if (arr1.size() <= 2)
		return;

	T mainChain = extractMainChain(arr1);
	log("Main chain: " + createSeq(mainChain), INFO);

	sort(mainChain, arr1);

	// sort()
}

void PmergeMe::execute(ContType type)
{
	auto start = std::chrono::high_resolution_clock::now();

	sort(this->numVec, this->numVec);


	// Simulate some work by sleeping for 1 second (1,000,000 microseconds)
	std::this_thread::sleep_for(std::chrono::seconds(1));

	auto end = std::chrono::high_resolution_clock::now();

	switch (type)
	{
		case VECTOR:
			this->vecUsecs = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
			break;
		case LIST:
			this->listUsecs = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
			break;
	}
}


void PmergeMe::run()
{
	log("Before: " + createSeq(this->argv), INFO);
	execute(VECTOR);
	// execute(LIST);
	log("After: " + createSeq(this->numVec), SUCCESS);
	printTime(this->numVec, VECTOR, this->listUsecs);
	// printTime(this->numList, LIST, this->vecUsecs);
}

void PmergeMe::log(std::string message, LogType type)
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

std::string PmergeMe::Error::getMessage() const
{
	return this->message;
}

PmergeMe::Error::Error(const std::string& message)
{
	this->message = message;
}