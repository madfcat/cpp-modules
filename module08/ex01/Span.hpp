/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:20:04 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/17 18:52:13 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <climits>
#include <exception>
#include <algorithm>
#include <cmath>
#include <iostream>

class Span
{
	private:
		std::vector<int> data;

	public:
		Span();
		Span(unsigned int);
		Span(const Span&);
		Span& operator=(const Span&);
		~Span();

		void	addNumber(int);
		void	addNumbers(std::vector<int>::iterator, std::vector<int>::iterator);
		int		shortestSpan();
		int		longestSpan();
};
