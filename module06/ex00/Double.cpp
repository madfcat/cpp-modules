/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:41:55 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/15 20:10:09 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"

Double::Double() : value(0) {}

Double::Double(double value) : value(value) {}

Double::Double(const Double &other)
{
	this->value = other.value;
}

Double &Double::operator=(const Double &other)
{
	if (this != &other)
		this->value = other.value;
	return *this;
}

Double::~Double() {}

double Double::getValue() const
{
	return this->value;
}

std::ostream &operator<<(std::ostream &os, const Double &doubleNum)
{
	os << doubleNum.getValue();
	if (std::floor(doubleNum.getValue()) == doubleNum.getValue() &&
		doubleNum.getValue() != std::numeric_limits<double>::infinity() &&
		doubleNum.getValue() != -std::numeric_limits<double>::infinity())
		os << ".0";
	return os;
}