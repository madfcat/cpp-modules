/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:53:48 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/15 21:58:14 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Helper.hpp"

std::string Helper::detect_type(std::string str)
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

		/* Detect int */
		if (str == std::to_string(std::stoi(str)))
			return "int";

		/* Detect float */
		if (str.substr(0, size(str) - 1) == std::to_string(std::stof(str)).substr(0, size(str) - 1) &&
			str[size(str) - 1] == 'f')
			return "float";

		/* Detect double */
		if (str == std::to_string(std::stod(str)).substr(0, size(str)))
			return "double";

		return "unknown";
	}
	catch (const std::exception &e)
	{
		return "unknown";
	}
}

std::string Helper::convert_char(char c)
{
	if (std::isprint(c))
		return "'" + std::string(1, c) + "'";
	return "Non displayable";
}



template <typename T>
void Helper::printOutput(const T &value, std::string type)
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
		std::cout << "char: " << convert_char(static_cast<char>(value)) << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	/* nan, +inf, -inf, +inff, -inff */
	else
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
	}

	std::cout << "float: " << Float(static_cast<float>(value)) << std::endl;
	std::cout << "double: " << Double(static_cast<double>(value)) << std::endl;
}

// Explicit instantiation for necessary types
template void Helper::printOutput(const char&, std::string);
template void Helper::printOutput(const int&, std::string);
template void Helper::printOutput(const float&, std::string);
template void Helper::printOutput(const double&, std::string);