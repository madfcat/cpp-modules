/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:34:51 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/27 20:39:09 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::farctionalBitsNumber = 8;

Fixed::Fixed()
{
	this->setRawBits(0);
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &otherNumber)
{
	this->setRawBits(otherNumber.getRawBits());
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& otherNumber)
{
	if (this != &otherNumber)
	{
		this->setRawBits(otherNumber.getRawBits());
		// std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	setRawBits(value);
	this->value = this->value << Fixed::getFractionalBitsNumber();
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float value)
{
	setRawBits(static_cast<int>(std::roundf(value * 256.0)));
	// std::cout << "Float constructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (value);
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

int Fixed::toInt( void ) const
{
	return (this->getRawBits() >> Fixed::getFractionalBitsNumber());
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / 256.0);
}

std::ostream & operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

int Fixed::getFractionalBitsNumber()
{
	return (Fixed::farctionalBitsNumber);
}

int Fixed::floatToFix(const float floatNumber)
{
	return (static_cast<int>(std::roundf(floatNumber * 256.0)));
}

/* Comparison operators */

Fixed Fixed::operator>(const Fixed& b)
{
	return (this->value > b.value);
}

Fixed Fixed::operator<(const Fixed& b)
{
	return (this->value < b.value);
}

Fixed Fixed::operator>=(const Fixed& b)
{
	return (this->value >= b.value);
}

Fixed Fixed::operator<=(const Fixed& b)
{
	return (this->value <= b.value);
}

Fixed Fixed::operator==(const Fixed& b)
{
	return (this->value == b.value);
}

Fixed Fixed::operator!=(const Fixed& b)
{
	return (this->value <= b.value);
}

/* Arithmetic operators */

Fixed Fixed::operator+(const Fixed& b)
{
	Fixed newFixedNumber;

	newFixedNumber.value = this->value + b.value;
	return newFixedNumber;
}

Fixed Fixed::operator-(const Fixed& b)
{
	Fixed newFixedNumber;

	newFixedNumber.value = this->value - b.value;
	return newFixedNumber;
}

Fixed Fixed::operator*(const Fixed& b)
{
	Fixed newFixedNumber;

	// newFixedNumber.value = this->value * b.value;

	newFixedNumber.value = static_cast<int>((unsigned long long)this->value * (unsigned long long)b.value >> Fixed::getFractionalBitsNumber());
	return newFixedNumber;
}

Fixed Fixed::operator/(const Fixed& b)
{
	Fixed newFixedNumber;
	newFixedNumber.value = static_cast<int>(static_cast<unsigned long long>(this->value) << Fixed::getFractionalBitsNumber() / b.value);
	return newFixedNumber;
}

/* Increment, decrement */

Fixed& Fixed::operator++()
{
	this->value = Fixed::floatToFix(this->toFloat() + 1/256.0);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->operator++();
	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->value = Fixed::floatToFix(this->toFloat() + 1/256.0);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->operator--();
	return (tmp);
}

/* Min, max */
Fixed Fixed::min(Fixed& a, Fixed& b)
{
	if (a.value < b.value)
		return (a);
	return (b);
}

Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.value < b.value)
		return (a);
	return (b);
}

Fixed Fixed::max(Fixed& a, Fixed& b)
{
	if (a.value > b.value)
		return (a);
	return (b);
}

Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.value > b.value)
		return (a);
	return (b);
}
