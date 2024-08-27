/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:11:45 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/27 22:20:08 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <set>
#include <climits>
#include <exception>
#include <algorithm>
#include <cmath>
#include <iostream>

class Span
{
	private:
		std::vector<int>	data;

	public:
		Span();
		Span(unsigned int);
		Span(const Span&);
		Span& operator=(const Span&);
		~Span();

		void				addNumber(int);
		void				addNumbers(std::vector<int>::iterator, std::vector<int>::iterator);
		int					shortestSpan();
		int					longestSpan();
};
