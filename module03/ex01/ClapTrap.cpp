/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:28:34 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/24 17:55:30 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name), points(10), energyPoints(10), attackDamage(0) {
	std::cout << this->name << ": ClapTrap constructor called." << std::endl;
	std::cout << this->name << ": Hit points = " << this->points << std::endl;
	std::cout << this->name << ": Energy points = " << this->energyPoints << std::endl;
	std::cout << this->name << ": Attack points = " << this->attackDamage << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& otherClapTrap)
{
	this->name = otherClapTrap.name;
	this->points = otherClapTrap.points;
	this->energyPoints = otherClapTrap.energyPoints;
	this->attackDamage = otherClapTrap.attackDamage;
	std::cout << this->name << ": ClapTrap copy constructor called." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& otherClapTrap)
{
	if (this != &otherClapTrap)
	{
		this->name = otherClapTrap.name;
		this->points = otherClapTrap.points;
		this->energyPoints = otherClapTrap.energyPoints;
		this->attackDamage = otherClapTrap.attackDamage;
	}
	std::cout << this->name << ": ClapTrap assignment operator called." << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout <<  this->name << ": ClapTrap destructor called." << std::endl;
};

void	ClapTrap::attack(const std::string& target)
{
	if (this->points == 0)
	{
		std::cout <<  this->name << ": ClapTrap  can't attack. It is already dead." << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << this->name << ": ClapTrap  has no energy points." << std::endl;
		return ;
	}
	std::cout << this->name << ": ClapTrap  attacks " << target << ", causing " << this->attackDamage << " points of damage!"<< std::endl;
	this->energyPoints -= 1;
	std::cout << this->name << ": ClapTrap  lost 1 energy point." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->points == 0)
	{
		std::cout << this->name << ": ClapTrap  can't take any damage. It is already dead." << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << this->name << ": ClapTrap  has no energy points. " << std::endl;
		return ;
	}
	if (amount > this->points)
		this->points = 0;
	else
		this->points -= amount;
	std::cout << this->name << ": ClapTrap  is damaged by " << amount << " points. " << this->name << " hit points: " << this->points << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->points == 0)
	{
		std::cout << this->name << ": ClapTrap  can't be repaired. It is already dead." << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << this->name << ": ClapTrap  has no energy points." << std::endl;
		return ;
	}
	this->points += amount;
	std::cout << this->name << ": ClapTrap  is repaired by " << amount << " points. " << this->name << " hit points: " << this->points << std::endl;
	this->energyPoints -= 1;
	std::cout << this->name << ": ClapTrap  lost 1 energy point." << std::endl;
}