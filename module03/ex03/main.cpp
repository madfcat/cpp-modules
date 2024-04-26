/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:40:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/25 21:55:22 by vshchuki         ###   ########.fr       */
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
	diamondTrap1.highFivesGuys();
	diamondTrap1.whoAmI();
	}
	std::cout << std::endl;
	
	// {
	// std::cout << "fragTrap1" << std::endl;
	// FragTrap fragTrap1("FragTrap1");
	// fragTrap1.takeDamage(0);

	// std::cout << "fragTrap2" << std::endl;
	// FragTrap fragTrap2(fragTrap1);
	// fragTrap2.takeDamage(0);
	
	// std::cout << "fragTrap3" << std::endl;
	// FragTrap fragTrap3 = fragTrap1;
	// fragTrap3.takeDamage(0);
	// }
	std::cout << std::endl;

	return (0);
}
