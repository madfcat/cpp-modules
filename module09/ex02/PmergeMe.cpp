/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:53:23 by vshchuki          #+#    #+#             */
/*   Updated: 2024/09/19 13:34:42 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const std::map<ContType, std::string> PmergeMe::containerTypes = {{VECTOR, "vector"}, {LIST, "list"}};

PmergeMe::PmergeMe()
{
	log("PmergeMe default constructor called", DEBUG);
}

template <typename T>
void PmergeMe::initArr(const int argc, const char* argv[], T& container, long long& usecs)
{
	auto start = std::chrono::high_resolution_clock::now();

	this->argv = std::vector<std::string>(argv + 1, argv + argc);
	for (int i = 1; i < argc; i++)
	{
		int newNum = std::stoi(argv[i]);
		auto it = std::find_if(container.begin(), container.end(), [newNum](const PmergeMe::Rec& rec) {
			return rec.mainChain == newNum;
		});
		if (it != container.end()) {
			throw PmergeMe::Error("This element is not unique: " + std::to_string(newNum));
		}

		if (newNum <= 0)
			throw PmergeMe::Error("Not a positive number: " + std::to_string(newNum));

		container.emplace_back(newNum);
	}
	
	auto end = std::chrono::high_resolution_clock::now();
	usecs = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

PmergeMe::PmergeMe(const int argc, const char* argv[])
{
	log("PmergeMe constructor called", DEBUG);
	initArr(argc, argv, this->numVec, this->vecUsecs);
	initArr(argc, argv, this->numList, this->listUsecs);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	log("PmergeMe copy constructor called", DEBUG);
	this->numVec = other.numVec;
	this->numList = other.numList;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	log("PmergeMe assignment operator called", DEBUG);
	if (this != &other)
	{
		this->numVec = other.numVec;
		this->numList = other.numList;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	log("PmergeMe destructor called", DEBUG);
}

/**
 * Methods
 */

/* Vector */

std::vector<PmergeMe::Rec>	PmergeMe::createInitPairs(std::vector<PmergeMe::Rec>& arr)
{
	std::vector<PmergeMe::Rec> newArr;
	for (unsigned long i = 1; i < arr.size(); i += 2)
	{
		newArr.emplace_back(arr[i].mainChain, &arr[i], &arr[i - 1]);
	}
	// Handle last element
	if (arr.size() % 2 == 1)
	{
		newArr.emplace_back(EMPTY, nullptr, &arr[arr.size() - 1]);
	}
	return newArr;
}

void PmergeMe::swapInit(std::vector<PmergeMe::Rec>& arr)
{
	for (unsigned long i = 1; i < arr.size(); i += 2)
	{

		if (arr[i].mainChain < arr[i - 1].mainChain)
		{	
			std::swap(arr[i], arr[i - 1]);
		}
	}
}

/**
 * t represents the next b to insert into "main chain"
 */
unsigned long findT(unsigned long arrSize, unsigned long k)
{
	unsigned long t = (std::pow(2, k + 1) + std::pow(-1, k)) / 3 - 1;
	t = t <= arrSize - 1 ? t : arrSize - 1;
	return t;
}

void PmergeMe::insertAs(unsigned long& lastT, unsigned long& addAFromIndex,
						std::vector<PmergeMe::Rec>& newArr, std::vector<PmergeMe::Rec>& insertionArr)
{
	log("addAFromIndex: " + std::to_string(addAFromIndex) +
		", lastT: " + std::to_string(lastT), DEBUG);
	for (unsigned long i = addAFromIndex; i <= lastT; i++)
	{
		if (newArr[i].mainChain == EMPTY)
			continue;
		if (i < newArr.size() && newArr[i].pair.first != nullptr)
			insertionArr.emplace_back(*newArr[i].pair.first);
		else
		{
			insertionArr.emplace_back(newArr[i]);
		}
		log("pushed A: " + std::to_string(newArr[i].mainChain), DEBUG);
	}
}

void PmergeMe::insertBs(unsigned long& lastT, unsigned long& addAFromIndex,
						std::vector<PmergeMe::Rec>& newArr, std::vector<PmergeMe::Rec>& insertionArr)
{
	log("-- Now inserting Bs. lastT: " + std::to_string(lastT) +
		", till addAFromIndex - 1: " + std::to_string(addAFromIndex - 1), DEBUG);
	for (unsigned long i = lastT; i != addAFromIndex - 1; i--)
	{
		unsigned long low = 0;
		unsigned long top = insertionArr.size() - 1;
		unsigned long mid = 0;

		while (low <= top)
		{
			mid = low + (top - low) / 2;
			if (newArr[i].pair.second->mainChain < insertionArr[mid].mainChain)
			{
				if (mid == 0)
					break;  // Avoid underflow, no valid position to move `top` down
				top = mid - 1;
			}
			else
			{
				if (mid >= insertionArr.size() - 1)
					break;  // Avoid overflow, no valid position to move `low` up
				low = low == insertionArr.size() - 1 ? low : mid + 1;
			}
		}

		// Check if number is bigger than the biggest in arr
		if (insertionArr[low].mainChain < newArr[i].pair.second->mainChain)
			low++;
		insertionArr.insert(insertionArr.begin() + low, Rec(*newArr[i].pair.second));
		log("pushed B: " + std::to_string(newArr[i].pair.second->mainChain), DEBUG);
	}
	log("--- Stop inserting Bs", DEBUG);
}

void PmergeMe::insertSort(std::vector<PmergeMe::Rec>& newArr, std::vector<PmergeMe::Rec>& insertionArr)
{
	/* Insert b1, a1 */
	insertionArr.emplace_back(*newArr[0].pair.second);
	insertionArr.emplace_back(*newArr[0].pair.first);
	
	unsigned long k = 2; 
	unsigned long lastT = findT(newArr.size(), k);
	unsigned long addAFromIndex = 1;

	while(42)
	{
		/* Insert a's */
		insertAs(lastT, addAFromIndex, newArr, insertionArr);

		printArr(insertionArr, "Base Pair populated a's + b0");

		/* Insert b's */
		insertBs(lastT, addAFromIndex, newArr, insertionArr);

		/* Move addAFromIndex after the last t, Increase k, Find new t*/
		addAFromIndex = lastT + 1;
		k++;
		lastT = findT(newArr.size(), k);

		if (addAFromIndex > newArr.size() - 1)
		{
			log("break ", DEBUG);
			break;
		}
	}
}

std::vector<PmergeMe::Rec> PmergeMe::sortVec(std::vector<PmergeMe::Rec>& arr)
{
	swapInit(arr);

	/* Base case */
	if (arr.size() <= 2)
		return arr;

	std::vector<PmergeMe::Rec> initSeq = createInitPairs(arr);
	printArr(initSeq);

	/* Save last b without a */
	PmergeMe::Rec leftOut;
	if (initSeq.back().mainChain == EMPTY)
	{
		leftOut = initSeq.back();
		initSeq.pop_back();
		printEl(leftOut, "Left Out Pair");
	}

	log("-------", DEBUG);
	printArr(initSeq);
	log("------- Let's start recursion -------", DEBUG);

	/* Sort recursively */
	std::vector<PmergeMe::Rec> newArr = sortVec(initSeq);

	/**
	 *  Prepare for Insertion sort
	 * */
	log("------- Before insertion -------", DEBUG);
	printArr(newArr);
	log("---", DEBUG);

	/* Push back last b without a */
	if (leftOut.mainChain == EMPTY)
	{
		newArr.push_back(leftOut);
		log("pushed leftOut: " + std::to_string(newArr.back().mainChain), DEBUG);
	}

	if (newArr[0].pair.first == nullptr) // top level
		return newArr;

	/* Insertion Sort */
	std::vector<PmergeMe::Rec> insertionArr;
	insertSort(newArr, insertionArr);

	printArr(insertionArr, "Base Pair before return");
	return insertionArr;
}

std::vector<PmergeMe::Rec> PmergeMe::executeVec()
{
	auto start = std::chrono::high_resolution_clock::now();
	std::vector<PmergeMe::Rec> result = sortVec(this->numVec);

	auto end = std::chrono::high_resolution_clock::now();
	this->vecUsecs += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	return result;
}

/* List */

std::list<PmergeMe::Rec>	PmergeMe::createInitPairs(std::list<PmergeMe::Rec>& arr)
{
	std::list<PmergeMe::Rec> newArr;
	auto it = arr.begin();
	auto nextIt = std::next(it);

	while (nextIt != arr.end() && it != arr.end())
	{
		newArr.emplace_back(nextIt->mainChain, &(*nextIt), &(*it));
		std::advance(it, 1);
		if (it == arr.end())
			break;
		std::advance(nextIt, 1);
		if (nextIt == arr.end())
			break;
		std::advance(it, 1);
		if (it == arr.end())
			break;
		std::advance(nextIt, 1);
		if (nextIt == arr.end())
			break;
	}

	// Handle last element if the size is odd
	if (arr.size() % 2 == 1)
	{
		newArr.emplace_back(EMPTY, nullptr, &(*it));
	}
	return newArr;
}

template <typename T>
typename std::list<T>::iterator PmergeMe::getElementAtIndex(std::list<T>& lst, size_t index)
{
	if (index >= lst.size())
		throw PmergeMe::Error("Index out of bounds: " + std::to_string(index) + "for size: " + std::to_string(lst.size()));

	auto it = lst.begin();
	std::advance(it, index);
	return it;
}

void PmergeMe::swapInit(std::list<PmergeMe::Rec>& arr)
{
	for (unsigned long i = 1; i < arr.size(); i += 2)
	{
		auto it1 = getElementAtIndex(arr, i);
		auto it2 = getElementAtIndex(arr, i - 1);

		if (it1->mainChain < it2->mainChain)
		{
			std::swap(*it1, *it2);  // Dereference iterators to swap the elements
		}
	}
}

void PmergeMe::insertAs(unsigned long& lastT, unsigned long& addAFromIndex,
						std::list<PmergeMe::Rec>& newArr, std::list<PmergeMe::Rec>& insertionArr)
{
	log("addAFromIndex: " + std::to_string(addAFromIndex) +
		", lastT: " + std::to_string(lastT), DEBUG);
	for (unsigned long i = addAFromIndex; i <= lastT; i++)
	{
		if (getElementAtIndex(newArr, i)->mainChain == EMPTY)
			continue;
		if (i < newArr.size() && getElementAtIndex(newArr, i)->pair.first != nullptr)
			insertionArr.emplace_back(*getElementAtIndex(newArr, i)->pair.first);
		else
		{
			insertionArr.emplace_back(*getElementAtIndex(newArr, i));
		}
		log("pushed A: " + std::to_string(getElementAtIndex(newArr, i)->mainChain), DEBUG);
	}
}

void PmergeMe::insertBs(unsigned long& lastT, unsigned long& addAFromIndex,
						std::list<PmergeMe::Rec>& newArr, std::list<PmergeMe::Rec>& insertionArr)
{
	log("-- Now inserting Bs. lastT: " + std::to_string(lastT) +
		", till addAFromIndex - 1: " + std::to_string(addAFromIndex - 1), DEBUG);
	for (unsigned long i = lastT; i != addAFromIndex - 1; i--)
	{
		unsigned long low = 0;
		unsigned long top = insertionArr.size() - 1;
		unsigned long mid = 0;

		while (low <= top)
		{
			mid = low + (top - low) / 2;
			if (getElementAtIndex(newArr, i)->pair.second->mainChain < getElementAtIndex(insertionArr, mid)->mainChain)
			{
				if (mid == 0)
					break;  // Avoid underflow, no valid position to move `top` down
				top = mid - 1;
			}
			else
			{
				if (mid >= insertionArr.size() - 1)
					break;  // Avoid overflow, no valid position to move `low` up
				low = low == insertionArr.size() - 1 ? low : mid + 1;
			}
		}

		// Check if number is bigger than the biggest in arr
		if (getElementAtIndex(insertionArr, low)->mainChain < getElementAtIndex(newArr, i)->pair.second->mainChain)
			insertionArr.insert(insertionArr.end(), Rec(*getElementAtIndex(newArr, i)->pair.second));
		else
			insertionArr.insert(getElementAtIndex(insertionArr, low), Rec(*getElementAtIndex(newArr, i)->pair.second));
		log("pushed B: " + std::to_string(getElementAtIndex(newArr, i)->pair.second->mainChain), DEBUG);
	}
	log("--- Stop inserting Bs", DEBUG);
}

void PmergeMe::insertSort(std::list<PmergeMe::Rec>& newArr, std::list<PmergeMe::Rec>& insertionArr)
{
	/* Insert b1, a1 */
	insertionArr.emplace_back(*getElementAtIndex(newArr, 0)->pair.second);
	insertionArr.emplace_back(*getElementAtIndex(newArr, 0)->pair.first);

	unsigned long k = 2; 
	unsigned long lastT = findT(newArr.size(), k);
	unsigned long addAFromIndex = 1;

	while(42)
	{
		/* Insert a's */
		insertAs(lastT, addAFromIndex, newArr, insertionArr);

		printArr(insertionArr, "Base Pair populated a's + b0");

		/* Insert b's */
		insertBs(lastT, addAFromIndex, newArr, insertionArr);

		/* Move addAFromIndex after the last t, Increase k, Find new t*/
		addAFromIndex = lastT + 1;
		k++;
		lastT = findT(newArr.size(), k);

		if (addAFromIndex > newArr.size() - 1)
		{
			log("break ", DEBUG);
			break;
		}
	}
}

std::list<PmergeMe::Rec> PmergeMe::sortList(std::list<PmergeMe::Rec>& arr)
{
	swapInit(arr);
	printArr(arr, "Base Pair swapped");

	/* Base case */
	if (arr.size() <= 2)
		return arr;

	std::list<PmergeMe::Rec> initSeq = createInitPairs(arr);
	/* Save last b without a */
	PmergeMe::Rec leftOut;
	if (initSeq.back().mainChain == EMPTY)
	{
		leftOut = initSeq.back();
		initSeq.pop_back();
		printEl(leftOut, "Left Out Pair");
	}

	log("-------", DEBUG);
	printArr(initSeq, "Base Pair initSeq");
	log("------- Let's start recursion -------", DEBUG);

	/* Sort recursively */
	std::list<PmergeMe::Rec> newArr = sortList(initSeq);

	/**
	 *  Prepare for Insertion sort
	 * */
	log("------- Before insertion -------", DEBUG);
	printArr(newArr);
	log("---", DEBUG);

	/* Push back last b without a */
	if (leftOut.mainChain == EMPTY)
	{
		newArr.push_back(leftOut);
		log("pushed leftOut: " + std::to_string(newArr.back().mainChain), DEBUG);
	}

	if (getElementAtIndex(newArr, 0)->pair.first == nullptr) // top level
		return newArr;

	/* Insertion Sort */
	std::list<PmergeMe::Rec> insertionArr;
	insertSort(newArr, insertionArr);

	printArr(insertionArr, "Base Pair before return");
	return insertionArr;
}

std::list<PmergeMe::Rec> PmergeMe::executeList()
{
	auto start = std::chrono::high_resolution_clock::now();
	std::list<PmergeMe::Rec> result = sortList(this->numList);
	auto end = std::chrono::high_resolution_clock::now();
	this->listUsecs += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	return result;
}

template<typename T>
bool PmergeMe::checkSorted(T& container)
{
	return std::is_sorted(container.begin(), container.end(),
		[](const PmergeMe::Rec& a, const PmergeMe::Rec& b) {
			return a.mainChain < b.mainChain;
		}
	);
}

void PmergeMe::run()
{
	log("Before: " + createSeq(this->argv), INFO);

	/* List */
	std::list<PmergeMe::Rec> sortedList = executeList();
	bool isSortedList = checkSorted(sortedList);
	log("Is list sorted: " + std::to_string(isSortedList), DEBUG);
	log("After (list): " + createSeq(sortedList), DEBUG);

	/* Vector */
	std::vector<PmergeMe::Rec> sortedVec = executeVec();
	bool isSortedVec = checkSorted(sortedVec);
	log("Is vector sorted: " + std::to_string(isSortedVec), DEBUG);
	log("After: " + createSeq(sortedVec), SUCCESS);

	/* Time */
	printTime(this->numVec, VECTOR, this->vecUsecs);
	printTime(this->numList, LIST, this->listUsecs);
}


/* Logging */

template <typename T>
void PmergeMe::printTime(T& container, ContType type, long long usecs) const
{
	log("Time to process a range of " +
		std::to_string(container.size()) + " elements with " +
		"std::" + containerTypes.at(type) + " : " +
		std::to_string(usecs) + " us", INFO);
}

template <typename T>
std::string PmergeMe::createSeq(T& container) const
{
	std::ostringstream oss;
	for (auto it = container.begin(); it != container.end(); ++it) {
		if (it != container.begin())
			oss << " ";
		oss << *it;
	}
	return oss.str();
}

/* Print vector */

void PmergeMe::printArr(std::vector<PmergeMe::Rec>& arr, std::string msg)
{
	for (auto& el : arr)
	{
		printEl(el, msg);
	}
}

void PmergeMe::printEl(PmergeMe::Rec& el, std::string msg)
{
	log("mainChain: " + std::to_string(el.mainChain) + " | " + 
		msg + ": (" +
		(el.pair.first ? std::to_string(el.pair.first->mainChain) : "null") + ", " +
		(el.pair.second ? std::to_string(el.pair.second->mainChain) : "null")
		+ ")", DEBUG); 
}

/* Print list */

void PmergeMe::printArr(std::list<PmergeMe::Rec>& arr, std::string msg)
{
	auto it = arr.begin();

	while (it != arr.end())
	{
		printEl(*it, msg);
		std::advance(it, 1);
	}
}


void PmergeMe::log(std::string message, LogType type)
{
	switch (type)
	{
		case INFO:
			std::cout << "ℹ️ " << TEXT_BLUE ;
			break;
		case ERROR:
			std::cerr << "🚫 " << BG_RED << TEXT_WHITE ;
			std::cerr << message << RESET << std::endl;
			return ;
		case SUCCESS:
			std::cout << "✅ " << TEXT_GREEN ;
			break;
		case DEBUG:
			#ifdef DEBUG_MODE
				std::cout << "🛠 " << TEXT_YELLOW;
				break;
			#else
				return;  // Don't log anything if not in debug mode
			#endif
		case DEFAULT:
			break;
	}
	std::cout << message << RESET << std::endl;
}

/* Rec */
PmergeMe::Rec::Rec() : mainChain(NOT_INIT), pair(nullptr, nullptr) {};

PmergeMe::Rec::Rec(int value) : mainChain(value), pair(nullptr, nullptr) {}

PmergeMe::Rec::Rec(int value, PmergeMe::Rec* first, PmergeMe::Rec* second) : mainChain(value), pair(first, second) {}

PmergeMe::Rec::Rec(const PmergeMe::Rec& other) : mainChain(other.mainChain), pair(other.pair.first, other.pair.second) {}

PmergeMe::Rec& PmergeMe::Rec::operator=(const PmergeMe::Rec& other)
{
	if (this != &other)
	{
		mainChain = other.mainChain;
		pair = other.pair;
	}
	return *this;
}

PmergeMe::Rec::~Rec() {};

/* Error */

PmergeMe::Error::Error() {};

PmergeMe::Error::Error(const Error& other)
{
	this->message = other.message;
}

PmergeMe::Error::Error(const std::string& message)
{
	this->message = message;
}

PmergeMe::Error& PmergeMe::Error::operator=(const Error& other)
{
	if (this != &other)
		this->message = other.message;
	return (*this);
}

PmergeMe::Error::~Error() {};

std::string PmergeMe::Error::getMessage() const
{
	return this->message;
}

/* Output operator overload */

std::ostream& operator<<(std::ostream& os, const PmergeMe::Rec& rec)
{
	os << rec.mainChain;
	return os;
}