/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:56:11 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 23:30:29 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void square(int& a)
{
	a = a * a;
}

void reverse(std::string& str)
{
	std::string reversed = "";
	for (int i = str.length() - 1; i >= 0; i--)
	{
		reversed += str[i];
	}
	str = reversed;

}

int main( void )
{
	{
		std::cout << "Testing with int array:" << std::endl;
		const int arrSize = 5;
		int arr[arrSize] = {1, 2, 3, 4, 5};
		iter(arr, arrSize, square);
		for (int i = 0; i < arrSize; i++)
		{
			std::cout << arr[i] << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "Testing with int array:" << std::endl;
		const int arrSize = 5;
		std::string arr[arrSize] = {"sihT", "sekam", "esnes", "won", "):"};
		iter(arr, arrSize, reverse);
		for (int i = 0; i < arrSize; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
}
