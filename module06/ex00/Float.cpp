/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:41:51 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/15 20:10:19 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"

Float::Float() : value(0) {}

Float::Float(float value) : value(value) {}

Float::Float(const Float &other)
{
	this->value = other.value;
}

Float &Float::operator=(const Float &other)
{
	if (this != &other)
		this->value = other.value;
	return *this;
}

Float::~Float() {}

float Float::getValue() const
{
	return this->value;
}

std::ostream &operator<<(std::ostream &os, const Float &floatNum)
{
	os << floatNum.getValue();
	if (std::floor(floatNum.getValue()) == floatNum.getValue() &&
		floatNum.getValue() != std::numeric_limits<float>::infinity() &&
		floatNum.getValue() != -std::numeric_limits<float>::infinity())
		os << ".0";
	os << "f";
	return os;
}