/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:53:48 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/22 23:52:10 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Helper.hpp"


bool Helper::isValidPointNummber(std::string &str, bool isFloat)
{
	std::size_t found1 = str.find(".");
	std::size_t found2 = found1 != std::string::npos ? str.find(".", found1 + 1) : std::string::npos;
	std::size_t foundF = str.find("f");

	for (char& c : str)
	{
		if (!(std::isdigit(c) || (isFloat && c == 'f') || c == '.') && !(c == '-' && c == str[0]))
			return false;
	}
	if (found1 != std::string::npos && found2 == std::string::npos && (foundF == str.size() - 1 || !isFloat))
		return true;
	return false;
}

std::string Helper::detectType(std::string str)
{
	try
	{
		/* Detect nan, +inf, -inf, + inff, -inff */
		if (str == "nan" || str == "+inf" || str == "-inf" ||
			str == "+inff" || str == "-inff" || str == "inf" || str == "inff")
			return "pseudo";

		/* Detect char */
		if (str.size() == 3 && str[0] == '\'' && str[2] == '\'')
			return "char";

		/* Check empty string */
		if (str.size() == 0)
			return "unknown";

		/* Detect float */
		if (Helper::isValidPointNummber(str))
			return "float";

		if (Helper::isValidPointNummber(str, false))
			return "double";
		
		/* Detect int */
		if (str == std::to_string(std::stoi(str)))
			return "int";

		return "unknown or impossible";
	}
	catch (const std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
		return "overflow";
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return "unknown or impossible";
	}
}

std::string Helper::convert_char(char c)
{
	if (c < -127 || c > 127)
		return "Overflow";
	if (std::isprint(c))
		return "'" + std::string(1, c) + "'";
	return "Non displayable";
}

template <typename T>
void Helper::printOutput(const T &value, std::string type, std::string str)
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

	/* Not nan, +inf, -inf, +inff, -inff */
	if (type != "pseudo")
	{
		std::cout << "char: ";
		if (value > 127 || value < -128)
			std::cout << "Overflow" << std::endl;
		else
			std::cout << convert_char(static_cast<char>(value)) << std::endl;
		try
		{
			// std::cout << str << std::endl;
			std::stoi(str);
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << "int: " << "Overflow" << std::endl;
		}
	}
	/* nan, +inf, -inf, +inff, -inff */
	else
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
	}
	/* flaot, double */
	int precision = 1; 
	if (type == "float")
			precision = str.size() - str.find(".") - 2;
	if (type == "double")
			precision = str.size() - str.find(".") - 1;
	std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(value) << std::endl;
}

// Explicit instantiation for necessary types
template void Helper::printOutput(const char &, std::string, std::string);
template void Helper::printOutput(const int &, std::string, std::string);
template void Helper::printOutput(const float &, std::string, std::string);
template void Helper::printOutput(const double &, std::string, std::string);
