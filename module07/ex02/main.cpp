/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:45:06 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 23:51:12 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
	{
		std::cout << "=== Testing int array ===" << std::endl;
		Array<int> arr(5);
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			arr[i] = i;
		}
		std::cout << "Array size: " << arr.size() << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "=== Testing str array ===" << std::endl;
		Array<std::string> arr = Array<std::string>(5);
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			arr[i] = i;
		}
		std::cout << "Array size: " << arr.size() << std::endl;
		arr[0] = "Hello";
		arr[1] = "world";
		arr[2] = "I";
		arr[3] = "love";
		arr[4] = "C++";
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "=== Testing copy operator ===" << std::endl;
		Array<std::string> arr1(5);
		std::cout << "Array size: " << arr1.size() << std::endl;
		arr1[0] = "Hello";
		arr1[1] = "world";
		arr1[2] = "I";
		arr1[3] = "love";
		arr1[4] = "C++";

		Array<std::string> arr2 = arr1;
		arr2[0] = "Hi";
		arr2[3] = "hate";
		arr2[4] = "C";
		for (unsigned int i = 0; i < arr1.size(); i++)
		{
			std::cout << arr1[i] << std::endl;
		}
		std::cout << std::endl;
		for (unsigned int i = 0; i < arr1.size(); i++)
		{
			std::cout << arr2[i] << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "=== Testing copy assignment operator ===" << std::endl;
		Array<std::string> arr1;
		Array<std::string> arr2(5);
		std::cout << "Array size: " << arr2.size() << std::endl;
		arr2[0] = "Hello";
		arr2[1] = "world";
		arr2[2] = "I";
		arr2[3] = "love";
		arr2[4] = "C++";

		arr1 = arr2;
		arr2[0] = "Hi";
		arr2[3] = "hate";
		arr2[4] = "C";
		for (unsigned int i = 0; i < arr1.size(); i++)
		{
			std::cout << arr1[i] << std::endl;
		}
		std::cout << std::endl;
		for (unsigned int i = 0; i < arr1.size(); i++)
		{
			std::cout << arr2[i] << std::endl;
		}
	}
}