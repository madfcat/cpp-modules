/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:34:49 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/29 02:43:30 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int value;
		static const int farctionalBitsNumber;
		static const int epsilon;

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

		static int floatToFix(const float);

		/* Comparison operators */
		bool operator>(const Fixed& b);
		bool operator<(const Fixed& b);
		bool operator>=(const Fixed& b);
		bool operator<=(const Fixed& b);
		bool operator==(const Fixed& b);
		bool operator!=(const Fixed& b);

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

		Fixed abs(void);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
