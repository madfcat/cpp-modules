/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:28:34 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/24 16:05:47 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): points(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap constructor called." << std::endl;
	std::cout << "Hit points = " << this->points << std::endl;
	std::cout << "Energy points = " << this->energyPoints << std::endl;
	std::cout << "Attack points = " << this->attackDamage << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
	this->points = clapTrap.points;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& otherClapTrap)
{
	std::cout << "ClapTrap assignment operator called." << std::endl;
	if (this != &otherClapTrap)
	{
		this->points = otherClapTrap.points;
		this->energyPoints = otherClapTrap.energyPoints;
		this->attackDamage = otherClapTrap.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
};

void	ClapTrap::attack(const std::string& target)
{
	if (this->points == 0)
	{
		std::cout << "ClapTrap can't attack. It is already dead." << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap has no energy points." << std::endl;
		return ;
	}
	std::cout << "ClapTrap attacks " << target << ", causing " << this->attackDamage << " points of damage!"<< std::endl;
	this->energyPoints -= 1;
	std::cout << "ClapTrap lost 1 energy point." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->points == 0)
	{
		std::cout << "ClapTrap can't take any damage. It is already dead." << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap has no energy points." << std::endl;
		return ;
	}
	if (amount > this->points)
		this->points = 0;
	else
		this->points -= amount;
	std::cout << "ClapTrap is damaged by " << amount << " points. ClapTrap hit points: " << this->points << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->points == 0)
	{
		std::cout << "ClapTrap can't be repaired. It is already dead." << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap has no energy points." << std::endl;
		return ;
	}
	this->points += amount;
	std::cout << "ClapTrap is repaired by " << amount << " points. ClapTrap hit points: " << this->points << std::endl;
	this->energyPoints -= 1;
	std::cout << "ClapTrap lost 1 energy point." << std::endl;
}