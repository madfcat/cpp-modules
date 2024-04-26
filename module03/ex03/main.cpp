/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:40:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/26 15:50:46 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	{
	DiamondTrap diamondTrap1("DiamondTrap1");
	diamondTrap1.attack("Enemy #1");
	diamondTrap1.takeDamage(10);
	diamondTrap1.beRepaired(5);
	diamondTrap1.guardGate();
	diamondTrap1.highFivesGuys();
	diamondTrap1.whoAmI();
	}
	std::cout << std::endl;

	{
	std::cout << "====== Testing copy constructor / assignment operator ======" << std::endl;
	// copy constructor
	std::cout << "copy constructor:" << std::endl;
	DiamondTrap diamondTrap1("DiamondTrap1");
	DiamondTrap diamondTrap2 = diamondTrap1;
	DiamondTrap diamondTrap3(diamondTrap1);

	// assignment operator
	std::cout << "assignment operator:" << std::endl;
	DiamondTrap diamondTrap4("DiamondTrap4");
	diamondTrap4 = diamondTrap1;
	std::cout << "diamondTrap1:" << std::endl;
	diamondTrap1.takeDamage(1);
	diamondTrap1.whoAmI();
	std::cout << "diamondTrap2:" << std::endl;
	diamondTrap2.takeDamage(0);
	diamondTrap2.whoAmI();
	std::cout << "diamondTrap3:" << std::endl;
	diamondTrap3.takeDamage(0);
	diamondTrap3.whoAmI();
	std::cout << "diamondTrap1:" << std::endl;
	diamondTrap1.takeDamage(0);
	std::cout << std::endl;
	
	std::cout << "diamondTrap4:" << std::endl;
	diamondTrap4.whoAmI();
	diamondTrap4.takeDamage(1);
	diamondTrap4.beRepaired(1);
	}
	std::cout << std::endl;

	return (0);
}
