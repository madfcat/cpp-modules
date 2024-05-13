/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:43:01 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/13 19:56:33 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->name = "Unknown";
	this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
	std::cout << this->name << ": ScavTrap default constructor called." << std::endl;
	std::cout << this->name << ": Hit points = " << this->hitPoints << std::endl;
	std::cout << this->name << ": Energy points = " << this->energyPoints << std::endl;
	std::cout << this->name << ": Attack points = " << this->attackDamage << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
	std::cout << this->name << ": ScavTrap constructor called." << std::endl;
	std::cout << this->name << ": Hit points = " << this->hitPoints << std::endl;
	std::cout << this->name << ": Energy points = " << this->energyPoints << std::endl;
	std::cout << this->name << ": Attack points = " << this->attackDamage << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << this->name << ": ScavTrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << this->name << ": ScavTrap assignment operator called." << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << this->name << ": ScavTrap destructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout <<  this->name << ": ScavTrap can't attack. It is already dead." << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << this->name << ": ScavTrap has no energy points." << std::endl;
		return ;
	}
	std::cout << this->name << ": ScavTrap attacks " << target << ", causing " << this->attackDamage << " points of damage!"<< std::endl;
	this->energyPoints -= 1;
	std::cout << this->name << ": ScavTrap lost 1 energy point. Energy points left: " << this->energyPoints << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->name << ": ScavTrap is now in Gate keeper mode" << std::endl;
}
