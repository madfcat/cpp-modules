/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:30:56 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/17 14:14:21 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{}

Span::Span(unsigned int N)
{
	this->data.reserve(N);
}

Span::Span(const Span& other)
{
	this->data = other.data;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->data = other.data;
	}
	return (*this);
}

Span::~Span()
{}

void	Span::addNumber(int num)
{
	if (this->data.size() == this->data.capacity())
		throw std::exception();
	
	this->data.push_back(num);
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
