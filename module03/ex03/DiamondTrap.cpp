/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:17:48 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/14 16:06:04 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unknown_clap_name"), ScavTrap("Unknown"), FragTrap("Unknown"), name("Unknown")
{
	this->energyPoints = 50;
	std::cout << this->name << ": DiamondTrap default constructor called." << std::endl;
	std::cout << this->name << ": Hit points = " << this->hitPoints << std::endl;
	std::cout << this->name << ": Energy points = " << this->energyPoints << std::endl;
	std::cout << this->name << ": Attack points = " << this->attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	this->energyPoints = 50;
	std::cout << this->name << ": DiamondTrap constructor called." << std::endl;
	std::cout << this->name << ": Hit points = " << this->hitPoints << std::endl;
	std::cout << this->name << ": Energy points = " << this->energyPoints << std::endl;
	std::cout << this->name << ": Attack points = " << this->attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->name = other.name;
	std::cout << this->name << ": DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << this->name << ": DiamondTrap assignment operator called." << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return (*this);
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