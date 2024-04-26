/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:17:48 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/25 22:33:01 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	this->energyPoints = 50;
	std::cout << this->name << ": DiamondTrap constructor called." << std::endl;
	std::cout << this->name << ": Hit points = " << this->hitPoints << std::endl;
	std::cout << this->name << ": Energy points = " << this->energyPoints << std::endl;
	std::cout << this->name << ": Attack points = " << this->attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->name << ": DiamondTrap destructor called." << std::endl;
}

void DiamondTrap::attack(std::string target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << this->name << ": Who am I? DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}