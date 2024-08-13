/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:11:35 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/13 16:22:39 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : numbersRepeat(false)
{
	this->data.reserve(N);
}

Span::Span(const Span& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->data.reserve(other.data.capacity());
	this->data = other.data;
	this->dataSet = other.dataSet;
	this->numbersRepeat = other.numbersRepeat;
}

Span& Span::operator=(const Span& other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->data.reserve(other.data.capacity());
		this->data = other.data;
		this->dataSet = other.dataSet;
		this->numbersRepeat = other.numbersRepeat;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int num)
{
	if (this->data.size() == this->data.capacity())
		throw std::exception();

	this->data.push_back(num);
	if (!this->dataSet.insert(num).second)
	{
		std::cout << "This number is repeated: " << num << std::endl;
		this->numbersRepeat = true;
	}
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int range = std::distance(begin, end);
	if (this->data.size() + range > this->data.capacity())
		throw std::exception();

	this->data.insert(this->data.end(), begin, end);
}

int		Span::shortestSpan()
{
	if (this->data.size() < 2)
		throw std::exception();

	if (this->numbersRepeat)
		return 0;

	int shortestSpan = INT_MAX;
	int currSpan;
	std::set<int>::iterator prev = this->dataSet.begin();
	std::set<int>::iterator it = std::next(prev);

	for (; it != this->dataSet.end(); ++it, ++prev)
	{
		currSpan = std::abs(*it - *prev);
		if (currSpan < shortestSpan)
			shortestSpan = currSpan;
	}

	return shortestSpan;
}

int		Span::longestSpan()
{
	if (this->data.size() < 2)
		throw std::exception();

	return std::abs(*std::max_element(data.begin(), data.end()) - *std::min_element(data.begin(), data.end()));
}
