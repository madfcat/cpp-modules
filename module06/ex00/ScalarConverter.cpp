/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:24:58 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/15 21:42:03 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	try
	{
		std::string type = Helper::detect_type(str);
		std::cout << "type: " << type << std::endl;
		if (type == "char")
		{
			char charNum = str[1];
			Helper::printOutput(charNum);
		}
		else if (type == "int")
		{
			int intNum = std::stoi(str);
			Helper::printOutput(intNum);
		}
		else if (type == "float")
		{
			float floatNum = std::stof(str);
			Helper::printOutput(floatNum);
		}
		else if (type == "double")
		{
			double doubleNum = std::stod(str);
			Helper::printOutput(doubleNum);
		}
		else if (type == "pseudo")
		{
			double doubleNum = std::stod(str);
			Helper::printOutput(doubleNum, type);
		}
		else if (type == "unknown")
		{
			Helper::printOutput(0, type);
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
