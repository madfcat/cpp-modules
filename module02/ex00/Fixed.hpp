/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:34:49 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/27 01:30:14 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
