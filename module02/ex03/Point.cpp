/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:49:40 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/25 15:33:21 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0))
{
}

Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y))
{
}

Point::Point(const Point &point): x(Fixed(point.getX())), y(Fixed(point.getY()))
{
}

Point& Point::operator=(const Point& point)
{
	(void)point;
	return (*this);
}

Point::~Point()
{
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}

// void Point::setX(const Fixed x)
// {
// 	this->x = x;
// }

// void Point::setY(const Fixed y)
// {
// 	this->y = y;
// }
