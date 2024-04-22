/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:00:12 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/05 16:12:02 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# ifndef FIXED_HPP
#  include "Fixed.hpp"
# endif

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float, const float);
		Point(const Point&);
		Point& operator=(const Point&);
		~Point();

		Fixed getX(void) const;
		Fixed getY(void) const;
		void setX(const Fixed);
		void setY(const Fixed);

		// bool bsp( Point const a, Point const b, Point const c, Point const point);
};

#endif