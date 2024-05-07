/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:40:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/07 16:19:03 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	{
	FragTrap fragTrap1("FragTrap1");
	fragTrap1.attack("Enemy #1");
	fragTrap1.takeDamage(10);
	fragTrap1.beRepaired(5);
	fragTrap1.highFivesGuys();
	}
	std::cout << std::endl;

	{
	std::cout << "fragTrap1" << std::endl;
	FragTrap fragTrap1("FragTrap1");
	fragTrap1.takeDamage(0);

	std::cout << "fragTrap2" << std::endl;
	FragTrap fragTrap2(fragTrap1);
	fragTrap2.takeDamage(0);
	
	std::cout << "fragTrap3" << std::endl;
	FragTrap fragTrap3 = fragTrap1;
	fragTrap3.takeDamage(0);
	}
	std::cout << std::endl;

	return (0);
}
