/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:40:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/24 18:00:34 by vshchuki         ###   ########.fr       */
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
	
	return (0);
}
