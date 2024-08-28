/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:11:35 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/28 15:08:31 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N)
{
	this->data.reserve(N);
}

Span::Span(const Span& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->data.reserve(other.data.capacity());
	this->data = other.data;
}

Span& Span::operator=(const Span& other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->data.reserve(other.data.capacity());
		this->data = other.data;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int num)
{
	if (this->data.size() == this->data.capacity())
		throw std::exception();

	this->data.push_back(num);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int range = std::distance(begin, end);
	if (this->data.size() + range > this->data.capacity())
		throw std::exception();

	this->data.insert(this->data.end(), begin, end);
}

unsigned int		Span::shortestSpan()
{
	if (this->data.size() < 2)
		throw std::exception();

	std::vector<int> dataSorted = data;
	std::sort(dataSorted.begin(), dataSorted.end());

	int shortestSpan = INT_MAX;
	int prev = -1;

	std::for_each(dataSorted.begin(), dataSorted.end(), [&](int curr) {
		if (prev != -1)
		{
			int currSpan = curr - prev;
			if (currSpan < shortestSpan)
				shortestSpan = currSpan;
		}
		prev = curr;
	});

	return shortestSpan;
}

unsigned int		Span::longestSpan()
{
	if (this->data.size() < 2)
		throw std::exception();

	return *std::max_element(data.begin(), data.end()) - *std::min_element(data.begin(), data.end());
}
