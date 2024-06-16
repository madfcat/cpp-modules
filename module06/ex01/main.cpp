/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:30:47 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 16:12:05 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	{
		std::cout << "=== Test #1 ===" << std::endl;
		Data* data = new Data();
		uintptr_t raw = Serializer::serialize(data);
		Data* ptr = Serializer::deserialize(raw);

		std::cout << "Compares equal to the original pointer: " << std::boolalpha << (data == ptr) << std::endl;
		ptr->printData();

		delete data;
	}
	{
		std::cout << std::endl;
		std::cout << "=== Test #2 ===" << std::endl;
		Data* data = new Data(42, "Hello, world!", 'G');
		uintptr_t raw = Serializer::serialize(data);
		Data* ptr = Serializer::deserialize(raw);

		std::cout << "Compares equal to the original pointer: " << std::boolalpha << (data == ptr) << std::endl;

		ptr->printData();

		delete data;
	}
}
