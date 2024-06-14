/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:24:58 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/15 02:10:56 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string detect_type(std::string str)
{
	try
	{
	/* Detect nan, +inf, -inf, + inff, -inff */
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		return str;

	/* Detect char */
	if (str.size() == 1)
		return "char";

	/* Check empty string */
	if (str.size() == 0)
		// throw std::invalid_argument("empty argument");
		return "impossible";

	/* Check allowed chars */
	for (char &c : str)
	{
		if (!(isdigit(c) || c == 'f' || c == '.'))
			// throw std::invalid_argument("impossible!");
			return "impossible";
	}

	/* Detect float */
	if (str.substr(0, size(str) - 1) == std::to_string(std::stof(str)).substr(0, size(str) - 1) && str[size(str) - 1] == 'f')
		return "float";

/* 		std::size_t foundDot1 = str.find(".");
		std::size_t foundDot2 = str.find(".", foundDot1 + 1);
		std::size_t foundF = str.find("f");

		if (foundDot1 != std::string::npos && foundDot2 == std::string::npos && foundF == std::size(str))
			return "float"; */

	/* Detect double */
		// double v1 = std::stod(str);
		// std::cout << v1 << std::endl;
		// std::string v2 = std::to_string(v1);
		// std::cout << v2.substr(0, size(str)) << std::endl;
	if (str == std::to_string(std::stod(str)).substr(0, size(str)))
		return "double";

	/* Detect int */
	if (str == std::to_string(std::stoi(str)))
		return "int";

	// throw std::invalid_argument("impossible!!");
	return "impossible";
	}
	catch (const std::exception &e) {
		return "impossible";
	}
}

std::string convert_char(char c)
{
	if (std::isprint(c))
		return "'" + std::string(1, c) + "'";
	return "Non displayable";
}

std::string convert_float(float num)
{
	return std::to_string(num);
}

template<typename T>
void print_output(const T& value)
{
		std::cout << "char: " << convert_char(static_cast<char>(value)) << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "float: " << static_cast<float>(value) << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	try
	{
		std::string type = detect_type(str);

		if (type == "char")
		{
			char charNum = str[0];
			print_output(charNum);
		}
		else if (type == "int")
		{
			int intNum = std::stoi(str);
			print_output(intNum);
		}
		else if (type == "float")
		{
			float floatNum = std::stof(str);
			print_output(floatNum);
		}
		else if (type == "double")
		{
			double doubleNum = std::stod(str);
			print_output(doubleNum);
		}
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
