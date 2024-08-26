/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:44:46 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/26 13:40:47 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): arrSize(0), data(nullptr) {}

template <typename T>
Array<T>::Array(unsigned int n): arrSize(n), data(new T[n]) {
	for (unsigned int i = 0; i < n; i++)
	{
		this->data[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	std::cout << "Copy constructor called" << std::endl;
	delete[] this->data;
	this->arrSize = other.arrSize;
	this->data = new T[arrSize];
	for (unsigned int i = 0; i < this->arrSize; i++)
	{
		this->data[i] = other.data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		delete[] this->data;
		this->arrSize = other.arrSize;
		this->data = new T[arrSize];
		for (unsigned int i = 0; i < arrSize; i++)
		{
			data[i] = other.data[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->arrSize) {
		throw std::exception();
	}
	return this->data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->arrSize) {
		throw std::exception();
	}
	return this->data[index];
}

template <typename T>
unsigned int Array<T>::size()
{
	return this->arrSize;
}