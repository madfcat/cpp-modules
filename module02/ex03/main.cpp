/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:34:46 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/29 22:19:20 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/**
 * Inspired by: https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
*/
bool bsp( Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed zero = Fixed(0.0f);
   	Fixed one = Fixed(1.0f);

	Fixed denominator = ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
	if (denominator.abs() == Fixed())
		return (false);

	Fixed w1 = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
	Fixed w2 = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
	return (w1 > zero && w2 > zero && (w1 + w2) < one);
}

int	main( void )
{
	Point a1(0.0f, 0.0f);
	Point b1(4.0f, 0.0f);
	Point c1(2.0f, 4.0f);
	Point p1(3.0f, 1.0f);
	std::cout << std::boolalpha << "Res: " << bsp(a1, b1, c1, p1) << std::endl;
	std::cout << "----" << std::endl;

	Point a2(0.0f, 0.0f);
	Point b2(4.0f, 0.0f);
	Point c2(2.0f, 4.0f);
	Point p2(5.0f, 1.0f);
	std::cout << std::boolalpha << "Res: " << bsp(a2, b2, c2, p2) << std::endl;
	std::cout << "----" << std::endl;

	Point a3(0.0f, 0.0f);
	Point b3(0.0f, 5.0f);
	Point c3(5.0f, 0.0f);
	Point p3(15.0f, 15.0f);
	std::cout << std::boolalpha << "Res: " << bsp(a3, b3, c3, p3) << std::endl;
	std::cout << "----" << std::endl;

	Point a4(0.0f, 0.0f);
	Point b4(0.0f, 5.0f);
	Point c4(5.0f, 0.0f);
	Point p4(0.5f, 5.0f);
	std::cout << std::boolalpha << "Res: " << bsp(a4, b4, c4, p4) << std::endl;
	std::cout << "----" << std::endl;

	Point a5(0, 0);
	Point b5(10, 30);
	Point c5(20, 0);
	Point p5(10, 0);
	Point p6(10, 30);
	std::cout << std::boolalpha << "Res: " << bsp(a5, b5, c5, p5) << std::endl;
	std::cout << "----" << std::endl;
	std::cout << std::boolalpha << "Res: " << bsp(a5, b5, c5, p6) << std::endl;
	std::cout << "----" << std::endl;

	return 0;
}