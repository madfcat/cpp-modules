/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:49:40 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/28 00:46:43 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	(this->x) = Fixed(0);
	(this->y) = Fixed(0);
}

Point::Point(const float x, const float y)
{
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Point::Point(const Point &point)
{
	this->setX(point.getX());
	this->setY(point.getY());
}

Point& Point::operator=(const Point& point)
{
	if (this != &point)
	{
		this->setX(point.getX());
		this->setX(point.getX());
	}
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

void Point::setX(const Fixed x)
{
	this->x = x;
}

void Point::setY(const Fixed y)
{
	this->y = y;
}
