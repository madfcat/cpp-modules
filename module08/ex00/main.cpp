/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:26:08 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/26 15:57:56 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	{
		std::vector<int> vec = {1, 2, 3, 4, 5};
		try
		{
			int resultVec1 = easyfind(vec, 3);
			std::cout << "Found in vector: " << resultVec1 << std::endl;
			int resultVec2 = easyfind(vec, 6);
			std::cout << "Found in vector: " << resultVec2 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Value not found" << std::endl;
		}
	}
	{
		std::list<int> vec = {1, 2, 3, 4, 5};
		try
		{
			int resultVec1 = easyfind(vec, 3);
			std::cout << "Found in vector: " << resultVec1 << std::endl;
			int resultVec2 = easyfind(vec, 6);
			std::cout << "Found in vector: " << resultVec2 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Value not found" << std::endl;
		}
	}
}
