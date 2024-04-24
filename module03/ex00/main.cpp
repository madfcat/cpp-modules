/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:40:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/24 16:27:22 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	{
	ClapTrap clapTrap1;

	clapTrap1.attack("Enemy #1");
	clapTrap1.takeDamage(5);
	clapTrap1.beRepaired(5);
	}
	std::cout << std::endl;
	
	{
	ClapTrap clapTrap1;

	clapTrap1.attack("Enemy #2");
	clapTrap1.takeDamage(15);
	clapTrap1.beRepaired(10);
	clapTrap1.attack("Enemy #2");
	}
	std::cout << std::endl;

	{
	std::cout << "====== Testing copy constructor / assignment operator ======" << std::endl;
	// copy constructor
	ClapTrap clapTrap1;
	ClapTrap clapTrap2 = clapTrap1;
	ClapTrap clapTrap3(clapTrap1);

	// assignment operator
	ClapTrap clapTrap4;
	clapTrap4 = clapTrap1;
	std::cout << "clapTrap1:" << std::endl;
	clapTrap1.takeDamage(1);
	std::cout << "clapTrap2:" << std::endl;
	clapTrap2.takeDamage(0);
	std::cout << "clapTrap3:" << std::endl;
	clapTrap3.takeDamage(0);
	std::cout << "clapTrap1:" << std::endl;
	clapTrap1.takeDamage(0);
	std::cout << std::endl;
	
	std::cout << "clapTrap4:" << std::endl;
	clapTrap4.takeDamage(1);
	std::cout << "clapTrap1:" << std::endl;
	clapTrap1.takeDamage(0);
	std::cout << "clapTrap2:" << std::endl;
	clapTrap2.takeDamage(0);
	std::cout << "clapTrap3:" << std::endl;
	clapTrap3.takeDamage(0);
	}
	std::cout << std::endl;
	
	return (0);
}
