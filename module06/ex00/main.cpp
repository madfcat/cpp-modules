/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:53:12 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/05 00:26:24 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, const char *argv[])
{

	(void)argc;
	(void)argv;

	// to handle: -inff, inff, nanf, -inf, inf, nan


	try
	{
		double a = std::stod("14.05ff"); // implement char conversion
		int b = a;
		float c = a;
		std::cout << "Results: ";
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		std::cout << std::numeric_limits<double>::quiet_NaN() << std::endl;
		std::cout << std::numeric_limits<double>::infinity() << std::endl;
		std::cout << -std::numeric_limits<double>::infinity() << std::endl;

		std::cout << std::numeric_limits<char>::quiet_NaN() << std::endl;
		std::cout << std::numeric_limits<char>::infinity() << std::endl;
		std::cout << -std::numeric_limits<char>::infinity() << std::endl;

		std::cout << std::numeric_limits<int>::quiet_NaN() << std::endl;
		std::cout << std::numeric_limits<int>::infinity() << std::endl;
		std::cout << -std::numeric_limits<int>::infinity() << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Out of range: " << e.what() << std::endl;
	}



/* 	// char
	try
	{
		char a = std::stoi("a"); // implement char conversion
		std::cout << "char: ";
		std::cout << a << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Out of range: " << e.what() << std::endl;
	}

	// int
	try
	{
		int b = std::stoi("15");
		std::cout << "int: ";
		std::cout << b << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Out of range: " << e.what() << std::endl;
	}
	// float
	try
	{
		float c = std::stof("15.14f");
		std::cout << "float: ";
		std::cout << c << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Out of range: " << e.what() << std::endl;
	}
	// double
	try
	{
		double d = std::stod("15.14");
		std::cout << d << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Out of range: " << e.what() << std::endl;
	} */

	return 0;
}
