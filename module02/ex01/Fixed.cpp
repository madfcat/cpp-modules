/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:34:51 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/17 16:34:19 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBitsNumber = 8;

Fixed::Fixed()
{
	this->setRawBits(0);
	std::cout << "Default constructor called" << "\n";
}

Fixed::Fixed(const Fixed &otherNumber)
{
	this->setRawBits(otherNumber.getRawBits());
	std::cout << "Copy constructor called" << "\n";
}

Fixed& Fixed::operator=(const Fixed& otherNumber)
{
	if (this != &otherNumber)
	{
		this->setRawBits(otherNumber.getRawBits());
		std::cout << "Copy assignment operator called" << "\n";
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
}

Fixed::Fixed(const int value)
{
	setRawBits(value);
	this->value = this->value << this->fractionalBitsNumber;
	std::cout << "Int constructor called" << "\n";
}

Fixed::Fixed (const float value)
{
	setRawBits(static_cast<int>(std::roundf(value * 256.0)));
	std::cout << "Float constructor called" << "\n";
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
	return (Fixed::fractionalBitsNumber);
}
