/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:34:49 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/27 03:02:24 by vshchuki         ###   ########.fr       */
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
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
