/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:40:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/25 15:59:54 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	{
	ScavTrap scavTrap1("ScavTrap1");
	scavTrap1.attack("Enemy #1");
	scavTrap1.takeDamage(10);
	scavTrap1.beRepaired(5);
	scavTrap1.guardGate();
	}
	std::cout << std::endl;

	{
	std::cout << "scavTrap1" << std::endl;
	ScavTrap scavTrap1("ScavTrap1");
	scavTrap1.takeDamage(0);

	std::cout << "scavTrap2" << std::endl;
	ScavTrap scavTrap2(scavTrap1);
	scavTrap2.takeDamage(0);
	
	std::cout << "scavTrap3" << std::endl;
	ScavTrap scavTrap3 = scavTrap1;
	scavTrap3.takeDamage(0);

	}
	std::cout << std::endl;
	
	return (0);
}
