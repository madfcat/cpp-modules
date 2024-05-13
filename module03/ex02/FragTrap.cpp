/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:36:42 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/13 19:56:49 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "Unknown";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << this->name << ": FragTrap default constructor called." << std::endl;
	std::cout << this->name << ": Hit points = " << this->hitPoints << std::endl;
	std::cout << this->name << ": Energy points = " << this->energyPoints << std::endl;
	std::cout << this->name << ": Attack points = " << this->attackDamage << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << this->name << ": FragTrap constructor called." << std::endl;
	std::cout << this->name << ": Hit points = " << this->hitPoints << std::endl;
	std::cout << this->name << ": Energy points = " << this->energyPoints << std::endl;
	std::cout << this->name << ": Attack points = " << this->attackDamage << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << this->name << ": FragTrap copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << this->name << ": FragTrap assignment operator called." << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << this->name << ": FragTrap destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->name << ": FragTrap requests a high five!" << std::endl;
}
