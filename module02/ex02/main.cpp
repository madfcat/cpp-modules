/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:34:46 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/17 16:08:28 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << "\n";
	std::cout << ++a << "\n";
	std::cout << a << "\n";
	std::cout << a++ << "\n";
	std::cout << a << "\n";
	
	std::cout << b << "\n";
	
	std::cout << Fixed::max( a, b ) << "\n";

/* 	std::cout << "Testing comparisson operators:" << "\n";

	std::cout << "Is more?" << "\n";
	Fixed n1 = Fixed(1.0f);
	n1++;
	Fixed n2 = Fixed(1.0f);
	std::cout << n1 << " > " << n2 << "\n";
	std::cout <<  std::boolalpha << (n1 > n2) << "\n";
	std::cout << n1 << " > " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 > n2) << "\n";
	std::cout << n1 << " > " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 > n2) << "\n";
	std::cout << "\n";

	std::cout << "Is less?" << "\n";
	n1 = Fixed(2.0f);
	n1++;
	n2 = Fixed(2.0f);
	std::cout << n1 << " < " << n2 << "\n";
	std::cout <<  std::boolalpha << (n1 < n2) << "\n";
	std::cout << n1 << " < " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 < n2) << "\n";
	std::cout << n1 << " < " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 < n2) << "\n";
	std::cout << "\n";

	std::cout << "Is more or equal?" << "\n";
	n1 = Fixed(2.0f);
	n1++;
	n2 = Fixed(2.0f);
	std::cout << n1 << " >= " << n2 << "\n";
	std::cout <<  std::boolalpha << (n1 >= n2) << "\n";
	std::cout << n1 << " >= " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 >= n2) << "\n";
	std::cout << n1 << " >= " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 >= n2) << "\n";
	std::cout << "\n";

	std::cout << "Is less or equal?" << "\n";
	n1 = Fixed(2.0f);
	n1++;
	n2 = Fixed(2.0f);
	std::cout << n1 << " <= " << n2 << "\n";
	std::cout <<  std::boolalpha << (n1 <= n2) << "\n";
	std::cout << n1 << " <= " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 <= n2) << "\n";
	std::cout << n1 << " <= " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 <= n2) << "\n";
	std::cout << "\n";

	std::cout << "Are equal?" << "\n";
	n1 = Fixed(1.0f);
	n1++;
	n2 = Fixed(1.0f);
	std::cout << n1 << " == " << n2 << "\n";
	std::cout <<  std::boolalpha << (n1 == n2) << "\n";
	std::cout << n1 << " == " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 == n2) << "\n";
	std::cout << n1 << " == " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 == n2) << "\n";
	std::cout << "\n";

	std::cout << "Are not equal?" << "\n";
	n1 = Fixed(1.0f);
	n1++;
	n2 = Fixed(1.0f);
	std::cout << n1 << " != " << n2 << "\n";
	std::cout <<  std::boolalpha << (n1 != n2) << "\n";
	std::cout << n1 << " != " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 != n2) << "\n";
	std::cout << n1 << " != " << ++n2 << "\n";
	std::cout <<  std::boolalpha << (n1 != n2) << "\n";
	std::cout << "\n";

	std::cout << "Testing arithmetic operators:" << "\n";
	n1 = Fixed(15.0f);
	n2 = Fixed(3.0f);
	std::cout << n1 << " + " << n2 << " = "<< n1 + n2 << "\n";
	std::cout << n1 << " - " << n2 << " = "<< n1 - n2 << "\n";
	std::cout << n1 << " / " << n2 << " = "<< n1 / n2 << "\n";
	std::cout << n1 << " * " << n2 << " = "<< n1 * n2 << "\n";
	n1 = Fixed(14.4f);
	n2 = Fixed(0.3f);
	std::cout << n1 << " + " << n2 << " = "<< n1 + n2 << "\n";
	std::cout << n1 << " - " << n2 << " = "<< n1 - n2 << "\n";
	std::cout << n1 << " / " << n2 << " = "<< n1 / n2 << "\n";
	std::cout << n1 << " * " << n2 << " = "<< n1 * n2 << "\n";
	std::cout << "\n";

	std::cout << "Testing increment/decrement operators:" << "\n";

	n1 = Fixed(1.0f);
	std::cout << n1 << "\n";
	std::cout << --n1 << " <<--- pre-decrement"<< "\n";
	std::cout << n1 << "\n";
	std::cout << "\n";

	n1 = Fixed(1.0f);
	std::cout << n1 << "\n";
	std::cout << n1-- << " <<--- post-decrement"<< "\n";
	std::cout << n1 << "\n";
	std::cout << "\n";

	n1 = Fixed(1.0f);
	std::cout << n1 << "\n";
	std::cout << ++n1 << " <<--- pre-increment"<< "\n";
	std::cout << n1 << "\n";
	std::cout << "\n";

	n1 = Fixed(1.0f);
	std::cout << n1 << "\n";
	std::cout << n1++ << " <<--- post-increment"<< "\n";
	std::cout << n1 << "\n";
	std::cout << "\n";

	std::cout << "Testing min/max operators:" << "\n";
	n1 = Fixed(1.0f);
	n2 = Fixed(1.0f);

	std::cout << "Min?" << "\n";
	n1 = Fixed(1.0f);
	n2 = Fixed(1.0f);
	std::cout << n1 << " between " << n2 << "\n";
	std::cout << Fixed::min(n1, n2) << "\n";
	n1++;
	std::cout << n1 << " between " << n2 << "\n";
	std::cout << Fixed::min(n1, n2) << "\n";
	n2++;
	n2++;
	std::cout << n1 << " between " << n2 << "\n";
	std::cout << Fixed::min(n1, n2) << "\n";
	std::cout << "\n";

	std::cout << "Max?" << "\n";
	n1 = Fixed(1.0f);
	n2 = Fixed(1.0f);
	std::cout << n1 << " between " << n2 << "\n";
	std::cout << Fixed::max(n1, n2) << "\n";
	n1++;
	std::cout << n1 << " between " << n2 << "\n";
	std::cout << Fixed::max(n1, n2) << "\n";
	n2++;
	n2++;
	std::cout << n1 << " between " << n2 << "\n";
	std::cout << Fixed::max(n1, n2) << "\n";
	std::cout << "\n"; */

	return 0;
}