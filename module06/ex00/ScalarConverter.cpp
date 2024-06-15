/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:24:58 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/15 19:37:20 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string detect_type(std::string str)
{
	try
	{
		/* Detect nan, +inf, -inf, + inff, -inff */
		if (str == "nan" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
			return "special";

		/* Detect char */
		if (str.size() == 1)
			return "char";

		/* Check empty string */
		if (str.size() == 0)
			// throw std::invalid_argument("empty argument");
			return "unknown";

		/* Detect float */
		if (str.substr(0, size(str) - 1) == std::to_string(std::stof(str)).substr(0, size(str) - 1) && str[size(str) - 1] == 'f')
			return "float";

		/* Detect double */
		if (str == std::to_string(std::stod(str)).substr(0, size(str)))
			return "double";

		/* Detect int */
		if (str == std::to_string(std::stoi(str)))
			return "int";

		// throw std::invalid_argument("impossible!!");
		return "unknown";
	}
	catch (const std::exception &e) {
		return "unknown";
	}
}

std::string convert_char(char c)
{
	if (std::isprint(c))
		return "'" + std::string(1, c) + "'";
	return "Non displayable";
}


void coutFloat(const float& floatNum)
{
	std::cout << "float: " << floatNum;
	if (std::floor(floatNum) == floatNum && floatNum != std::numeric_limits<float>::infinity() && floatNum != -std::numeric_limits<float>::infinity())
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void coutDouble(const double& doubleNum)
{
	std::cout << "double: " << doubleNum;
	if (std::floor(doubleNum) == doubleNum && doubleNum != std::numeric_limits<double>::infinity() && doubleNum != -std::numeric_limits<double>::infinity())
		std::cout << ".0";
	std::cout << std::endl;;
}

template<typename T>
void printOutput(const T& value, std::string type = "unset")
{
	/* Wrong argument */
	if (type == "unknown")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "impossible" << std::endl;
		std::cout << "double: " << "impossible" << std::endl;
		return;
	}

	if (type != "special")
	{
		std::cout << "char: " << convert_char(static_cast<char>(value)) << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	/* nan, +inf, -inf, +inff, -inff */
	else
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
	}
	coutFloat(static_cast<float>(value));
	coutDouble(static_cast<double>(value));
}

void ScalarConverter::convert(std::string str)
{
	// try
	// {
		std::string type = detect_type(str);

		if (type == "char")
		{
			char charNum = str[0];
			printOutput(charNum);
		}
		else if (type == "int")
		{
			int intNum = std::stoi(str);
			printOutput(intNum);
		}
		else if (type == "float")
		{
			float floatNum = std::stof(str);
			printOutput(floatNum);
		}
		else if (type == "double")
		{
			double doubleNum = std::stod(str);
			printOutput(doubleNum);
		}
		else if (type == "special")
		{
			double doubleNum = std::stod(str);
			printOutput(doubleNum, type);
		}
		else if (type == "unknown")
		{
			printOutput(0, type);
		}
	// }
	// catch (const std::invalid_argument &e)
	// {
	// 	std::cout << "Invalid argument: " << e.what() << std::endl;
	// }
	// catch (const std::out_of_range &e)
	// {
	// 	std::cerr << "Out of range: " << e.what() << std::endl;
	// }
}
