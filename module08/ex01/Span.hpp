/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:20:04 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/17 14:14:23 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <climits>
#include <exception>
#include <algorithm>
#include <cmath>

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
		int		shortestSpan();
		int		longestSpan();
};
