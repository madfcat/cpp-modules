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

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << "\n";
	return (value);
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}
