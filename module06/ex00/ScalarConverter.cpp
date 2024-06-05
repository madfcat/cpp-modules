/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:24:58 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/05 00:01:32 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{

	std::cout << "char: ";
	try
	{
		float a = std::stof("14.05f"); // implement char conversion
		std::cout << "Result: ";
		std::cout << a << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Out of range: " << e.what() << std::endl;
	}
}
