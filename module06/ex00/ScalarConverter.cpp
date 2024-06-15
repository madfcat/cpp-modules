/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:24:58 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 01:38:12 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	try
	{
		std::string type = Helper::detectType(str);
		// std::cout << "type: " << type << std::endl;
		if (type == "char")
		{
			char charNum = str[1];
			Helper::printOutput(charNum, type, str);
		}
		else if (type == "int")
		{
			int intNum = std::stoi(str);
			Helper::printOutput(intNum, type, str);
		}
		else if (type == "float")
		{
			float floatNum = std::stof(str);
			Helper::printOutput(floatNum, type, str);
		}
		else if (type == "double")
		{
			double doubleNum = std::stod(str);
			Helper::printOutput(doubleNum, type, str);
		}
		else if (type == "pseudo")
		{
			double doubleNum = std::stod(str);
			Helper::printOutput(doubleNum, type, str);
		}
		else if (type == "unknown")
		{
			Helper::printOutput(0, type, str);
		}
		else if (type == "overflow")
		{
			std::cout << "Overflow :(" << std::endl;
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
	catch (const std::exception &e)
	{
		std::cerr << "Exception " << e.what() << std::endl;
	}
}
