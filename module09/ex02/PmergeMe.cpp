/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:53:23 by vshchuki          #+#    #+#             */
/*   Updated: 2024/09/01 23:16:46 by vshchuki         ###   ########.fr       */
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

// template <typename T>
// void compareSwap(T& arr1, T& arr2, int aInd)
// {
// 	if (arr1[aInd] < arr1[aInd - 1])
// 	{
// 		int temp = arr1[aInd];
// 		arr1[aInd] = arr1[aInd - 1];
// 		arr1[aInd - 1] = temp;

// 		if (arr1 != arr2)
// 		{
// 			// int temp1 = arr2[2 * aInd];
// 			// arr2[2 * aInd] = arr2[aInd];
// 			// arr2[aInd] = temp1;

// 			int temp2 = arr2[2 * aInd - 1];
// 			arr2[2 * aInd - 1] = arr2[2 * (aInd - 1) - 1];
// 			arr2[2 * (aInd - 1) - 1] = temp2;
// 		}
// 	}
// }

// template <typename T>
// T extractMainChain(T& arr)
// {
// 	T mainChain;
// 	for (size_t i = 1; i < arr.size(); i += 2) {
// 		mainChain.push_back(arr[i]);
// 	}
// 	return mainChain;
// }

// template <typename T>
// void PmergeMe::sort(T& arr1, T& arr2)
// {
// 	std::cout << "---" << std::endl;


// 	/* Divide into pairs */





// 	// Sorting

// 	/*
// 	1. Divide all numbers in pairs and swap them. Find the larger number in pairs. Sort pairs according to 
// 	these larger numbers using merge insertion recursively
// 	The base case is when main chain has only 2 numbers. Return vector with sorted indices.
// 	Outer function should apply this order to the numbers and its pairs.
// 	2. 
	
	
// 	*/

	

// 	/* Swap pairs to have a1, a2... as largest in pair*/

// 	for (unsigned long i = 1; i < arr1.size(); i += 2)
// 	{
// 		compareSwap(arr1, arr2, i);
// 	}
// 	log("Now swaped: " + createSeq(arr1), INFO);
// 	log("Now swaped prev: " + createSeq(arr2), INFO);
// 	if (arr1.size() <= 2)
// 		return;

// 	T mainChain = extractMainChain(arr1);
// 	log("Main chain: " + createSeq(mainChain), INFO);

// 	sort(mainChain, arr1);

// 	// sort()
// }

std::vector<RecursivePair>	PmergeMe::createInitPairs(std::vector<int>& arr1)
{
	std::vector<RecursivePair> split;
	for (unsigned long i = 1; i < arr1.size(); i += 2)
	{
		split.push_back(RecursivePair(arr1[i], arr1[i - 1]));
	}
	// Handle last element
	if (arr1.size() % 2 == 1)
	{
		split.push_back(RecursivePair(EMPTY_PAIR, arr1[arr1.size() - 1]));
	}

	return split;
}

// std::vector<RecursivePair>	PmergeMe::createRecPairs(std::vector<RecursivePair>& arr)
// {
// 	std::vector<RecursivePair> split;
// 	for (unsigned long i = 1; i < arr.size(); i += 2)
// 	{
// 		std::pair<int, int> pair;
// 		if (arr[i].isPairIntInt(pair))
// 		{
// 			split.push_back(RecursivePair(pair.value, arr[i - 1]));
// 		}
// 	}
// 	// Handle last element
// 	if (arr.size() % 2 == 1)
// 	{
// 		split.push_back(RecursivePair(EMPTY_PAIR, arr[arr.size() - 1]));
// 	}

// 	return split;
// }

void PmergeMe::swapInitSplit(std::vector<RecursivePair>& split)
{
		for (auto& rp : split)
		{
			std::pair<int, int> basePair;
			if (rp.isPairIntInt(basePair))
			{
				auto& basePair = std::get<std::pair<int, int>>(rp.value);
				if (basePair.second > basePair.first && basePair.first != EMPTY_PAIR)
				{
					std::swap(basePair.first, basePair.second);
				}
			}
		}
}

// void PmergeMe::mergeInsertMainChain(std::vector<RecursivePair>& arr)
// {
	
// 	auto split = splitRecPairs(arr);
// 	mergeInsertMainChain(split);
// }


void PmergeMe::sortVec(std::vector<int>& arr1)
{
	auto split = createInitPairs(arr1);
	swapInitSplit(split);

	std::pair<int, int> lastPair = {-2, -2};

	if (split.back().isPairIntInt(lastPair) && lastPair.first == -1)
	{
		split.pop_back();
	}

	for (const auto& pair : split) {
		// std::cout << pair.first << " " << pair.second << std::endl;
		if (std::holds_alternative<std::pair<int, int>>(pair.value))
		{
			const auto& basePair = std::get<std::pair<int, int>>(pair.value);
			std::cout << "Base Pair: (" << basePair.first << ", " << basePair.second << ")" << std::endl;
		}
		else
		{
			const auto& recursivePair = std::get<std::shared_ptr<std::pair<int, RecursivePair>>>(pair.value);
			std::cout << "First: " << recursivePair->first << std::endl;
			// processRecursivePair(recursivePair->second); // Recursively process the next level
		}
	}
	std::cout << "Last Pair: (" << lastPair.first << ", " << lastPair.second << ")" << std::endl;

	// mergeInsertMainChain(split);

	// push back lastPair
	// Insertion sort
}



void PmergeMe::execute(ContType type)
{
	auto start = std::chrono::high_resolution_clock::now();

	// sort(this->numVec, this->numVec);
	sortVec(this->numVec);

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