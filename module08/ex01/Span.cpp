/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:50:14 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/17 20:11:40 by vshchuki         ###   ########.fr       */
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

int		Span::shortestSpan()
{
	if (this->data.size() < 2)
		throw std::exception();

	int shortestSpan = INT_MAX;
	int currSpan;
	std::vector<int> sorted = data;
	std::vector<int>::iterator it;
	for (it = sorted.begin() + 1; it != sorted.end(); it++)
	{
		currSpan = std::abs(*std::prev(it) - *it);
		if (currSpan < shortestSpan)
			shortestSpan = currSpan;
	}

	return shortestSpan;
}

int		Span::longestSpan()
{
	if (this->data.size() < 2)
		throw std::exception();

	return *std::max_element(data.begin(), data.end()) - *std::min_element(data.begin(), data.end());
}
