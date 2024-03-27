/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:34:49 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/27 16:55:29 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
	private:
		int value;
		static const int farctionalBitsNumber;

	public:
		Fixed();
		Fixed(const Fixed &);
		Fixed& operator=(const Fixed&);
		~Fixed();
		Fixed(const int);
		Fixed(const float);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static int getFractionalBitsNumber();

		/* Comparison operators */
		Fixed operator>(const Fixed& b);
		Fixed operator<(const Fixed& b);
		Fixed operator>=(const Fixed& b);
		Fixed operator<=(const Fixed& b);
		Fixed operator==(const Fixed& b);
		Fixed operator!=(const Fixed& b);

		/* Arithmetic operators */
		Fixed operator+(const Fixed&);
		Fixed operator-(const Fixed&);
		Fixed operator*(const Fixed&);
		Fixed operator/(const Fixed&);

		/* Increment, decrement */
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		/* Min, max */
		static Fixed min(Fixed&, Fixed&);
		static Fixed min(const Fixed&, const Fixed&);
		static Fixed max(Fixed&, Fixed&);
		static Fixed max(const Fixed&, const Fixed&);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
