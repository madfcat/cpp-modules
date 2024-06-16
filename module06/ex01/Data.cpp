/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:44:28 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 16:07:36 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {}

Data::Data(int intNum, std::string str, char charNum)
{
	this->intNum = intNum;
	this->str = str;
	this->charNum = charNum;
}

Data::Data(const Data &other)
{
	this->intNum = other.intNum;
	this->str = other.str;
	this->charNum = other.charNum;
}

Data& Data::operator=(const Data &other)
{
	if (this != &other)
	{
		this->intNum = other.intNum;
		this->str = other.str;
		this->charNum = other.charNum;
	}
	return (*this);
}

Data::~Data() {}

void Data::printData()
{
	std::cout << "intNum: " << this->intNum << std::endl;
	std::cout << "str: " << this->str << std::endl;
	std::cout << "charNum: " << this->charNum << std::endl;
}
