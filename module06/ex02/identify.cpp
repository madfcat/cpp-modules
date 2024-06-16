/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:42:06 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 17:42:21 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

Base* generate(void)
{
	std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 3);

	int n = dist(mt);
	std::cout << "Generated: " << n << std::endl;
	switch (n)
	{
		case 1:
			return new A;
		case 2:
			return new B;
		case 3:
			return new C;
	}
	return nullptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) {
		std::cout << "Identified type: A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "Identified type: B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "Identified type: C" << std::endl;
	} else {
		std::cout << "Identified type: Base" << std::endl;
	}
}

void identify(Base& p)
{
	if (dynamic_cast<A*>(&p)) {
		std::cout << "Type: A" << std::endl;
	} else if (dynamic_cast<B*>(&p)) {
		std::cout << "Type: B" << std::endl;
	} else if (dynamic_cast<C*>(&p)) {
		std::cout << "Type: C" << std::endl;
	} else {
		std::cout << "Type: Base" << std::endl;
	}
}
