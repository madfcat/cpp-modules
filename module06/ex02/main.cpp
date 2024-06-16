/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:08:32 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 17:42:09 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

int main()
{
	{
		std::cout << "Identify from pointer:" << std::endl;
		int arraySize = 5;
		Base* obj[arraySize];

		for (int i = 0; i < arraySize; i++)
		{
			obj[i] = generate();
			identify(obj[i]);
		}
		for (int i = 0; i < arraySize; i++)
		{
			delete obj[i];
		}
	}
	{
		std::cout << std::endl;
		std::cout << "Identify from reference:" << std::endl;
		int arraySize = 5;
		Base* obj[arraySize];

		for (int i = 0; i < arraySize; i++)
		{
			obj[i] = generate();
			identify(*(obj[i]));
		}
		for (int i = 0; i < arraySize; i++)
		{
			delete obj[i];
		}
	}
}
