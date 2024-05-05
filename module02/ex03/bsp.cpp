/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:35:36 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/05 18:41:48 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float denominator = ((b.getY().toFloat() - c.getY().toFloat()) * (a.getX().toFloat() - c.getX().toFloat()) + (c.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat()));
	if (denominator == 0.0)
		return (false);

	float w1 = ((b.getY().toFloat() - c.getY().toFloat()) * (point.getX().toFloat() - c.getX().toFloat()) + (c.getX().toFloat() - b.getX().toFloat()) * (point.getY().toFloat() - c.getY().toFloat())) / denominator;
	float w2 = ((c.getY().toFloat() - a.getY().toFloat()) * (point.getX().toFloat() - c.getX().toFloat()) + (a.getX().toFloat() - c.getX().toFloat()) * (point.getY().toFloat() - c.getY().toFloat())) / denominator;
	return (w1 > 0 && w2 > 0 && (w1 + w2) < 1);
}