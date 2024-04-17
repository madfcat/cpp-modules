/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:34:51 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/28 18:41:57 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::farctionalBitsNumber = 8;

Fixed::Fixed()
{
	this->setRawBits(0);
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &otherNumber)
{
	this->setRawBits(otherNumber.getRawBits());
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& otherNumber)
{
	if (this != &otherNumber)
	{
		this->setRawBits(otherNumber.getRawBits());
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}
