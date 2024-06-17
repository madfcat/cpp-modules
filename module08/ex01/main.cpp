/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:19:59 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/17 20:18:09 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=== Tests with 10000 elements ===" << std::endl;
	{
		unsigned int vectorSize= 100000;
		Span sp = Span(vectorSize);

		for (unsigned int i = 0; i < vectorSize; i++)
			sp.addNumber(i);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=== Tests copy constructor ===" << std::endl;
	{
		unsigned int vectorSize= 10;
		Span sp1 = Span(vectorSize);
		for (unsigned int i = 0; i < vectorSize - 1; i++)
			sp1.addNumber(i + 1);

		Span sp2 = sp1;
		std::cout << "Shortest span for sp1: " << sp1.shortestSpan() << std::endl;
		std::cout << "Shortest span for sp2: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span for sp1: " << sp1.longestSpan() << std::endl;
		std::cout << "Longest span for sp2: " << sp2.longestSpan() << std::endl;

		std::cout << "Now let's ad 100 to sp1 and 200 to sp2" << std::endl;
		sp1.addNumber(100);
		sp2.addNumber(200);
		std::cout << "Shortest span for sp1: " << sp1.shortestSpan() << std::endl;
		std::cout << "Shortest span for sp2: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span for sp1: " << sp1.longestSpan() << std::endl;
		std::cout << "Longest span for sp2: " << sp2.longestSpan() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=== Tests assignemnt operator ===" << std::endl;
	{
		unsigned int vectorSize= 10;
		Span sp1 = Span(vectorSize);
		Span sp2;
		for (unsigned int i = 0; i < vectorSize - 1; i++)
			sp1.addNumber(i + 1);

		sp2 = sp1;
		std::cout << "Shortest span for sp1: " << sp1.shortestSpan() << std::endl;
		std::cout << "Shortest span for sp2: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span for sp1: " << sp1.longestSpan() << std::endl;
		std::cout << "Longest span for sp2: " << sp2.longestSpan() << std::endl;

		std::cout << "Now let's ad 100 to sp1 and 200 to sp2" << std::endl;
		sp1.addNumber(100);
		sp2.addNumber(200);
		std::cout << "Shortest span for sp1: " << sp1.shortestSpan() << std::endl;
		std::cout << "Shortest span for sp2: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span for sp1: " << sp1.longestSpan() << std::endl;
		std::cout << "Longest span for sp2: " << sp2.longestSpan() << std::endl;
		try
		{
			sp1.addNumber(1);
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "=== Test adding several numbers  ===" << std::endl;
	{
		unsigned int vectorSize= 10;
		Span sp1 = Span(vectorSize);
		for (unsigned int i = 0; i < vectorSize - 5; i++)
			sp1.addNumber(i + 1);

		std::cout << "Shortest span for sp1: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest span for sp1: " << sp1.longestSpan() << std::endl;
		std::vector<int> myArray = { 5, 6, 7, 8, 9 };
		sp1.addNumbers(myArray.begin(), myArray.end());
		std::cout << "Shortest span for sp1: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest span for sp1: " << sp1.longestSpan() << std::endl;
	}

	return 0;
}