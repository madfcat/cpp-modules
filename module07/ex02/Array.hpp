/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:18:00 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/26 13:39:54 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int arrSize;
		T* data = nullptr;

	public:
		Array();
		Array(unsigned int);
		Array(const Array<T>&);
		Array<T>& operator=(const Array<T>&);
		~Array();

		T& operator[](unsigned int);
		const T& operator[](unsigned int) const;

		unsigned int size();
};

#include "Array.tpp"