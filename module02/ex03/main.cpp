/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:34:46 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/05 18:43:41 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

void printCoordinates(Point const point)
{
	std::cout << "X: " << point.getX() << " Y: " << point.getY() << std::endl;
}
/**
 * Testing: https://www.desmos.com/calculator
*/
int	main( void )
{
	Point a1(0.0f, 0.0f);
	Point b1(4.0f, 0.0f);
	Point c1(2.0f, 4.0f);
	Point p11(3.0f, 1.0f);
	Point p12(5.0f, 1.0f);
	std::cout << std::boolalpha << "Test1-1: " << bsp(a1, b1, c1, p11) << std::endl;
	std::cout << std::boolalpha << "Test1-2: " << bsp(a1, b1, c1, p12) << std::endl;
	std::cout << "----" << std::endl;

	Point a2(0.0f, 0.0f);
	Point b2(0.0f, 5.0f);
	Point c2(5.0f, 0.0f);
	Point p21(2.0f, 2.0f);
	Point p22(15.0f, 15.0f);
	Point p23(0.5f, 5.0f);
	std::cout << std::boolalpha << "Test2-1: " << bsp(a2, b2, c2, p21) << std::endl;
	std::cout << std::boolalpha << "Test2-2: " << bsp(a2, b2, c2, p22) << std::endl;
	std::cout << std::boolalpha << "Test2-3: " << bsp(a2, b2, c2, p23) << std::endl;
	std::cout << "----" << std::endl;

	Point a3(0, 0);
	Point b3(10, 30);
	Point c3(20, 0);
	Point p31(10, 0);
	Point p32(10, 30);
	std::cout << std::boolalpha << "Test3-1: " << bsp(a3, b3, c3, p31) << std::endl;
	std::cout << std::boolalpha << "Test3-2: " << bsp(a3, b3, c3, p32) << std::endl;
	std::cout << "----" << std::endl;

	Point a4(4.7f, 9.0f);
	Point b4(-2.0f, -5.3f);
	Point c4(-1.6f, 7.8f);
	printCoordinates(a4);
	printCoordinates(b4);
	printCoordinates(c4);
	Point p41(2.0f, 2.0f);
	Point p42(0.0f, -1.5f);
	Point p43(0.5f, 5.0f);
	printCoordinates(p41);
	printCoordinates(p42);
	printCoordinates(p43);
	std::cout << std::boolalpha << "Test4-1: " << bsp(a4, b4, c4, p41) << std::endl;
	std::cout << std::boolalpha << "Test4-2: " << bsp(a4, b4, c4, p42) << std::endl;
	std::cout << std::boolalpha << "Test4-3: " << bsp(a4, b4, c4, p43) << std::endl;
	std::cout << std::boolalpha << "Test4-4: " << bsp(a4, b4, c4, a4) << std::endl;
	std::cout << std::boolalpha << "Test4-4: " << bsp(a4, b4, c4, b4) << std::endl;
	std::cout << std::boolalpha << "Test4-4: " << bsp(a4, b4, c4, c4) << std::endl;
	std::cout << "----" << std::endl;

	return (0);
}