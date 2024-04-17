/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:28:34 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/17 20:10:54 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): points(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	this->points = clapTrap.points;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& otherClapTrap)
{
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
		std::cout << "ClapTrap is already dead" << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap has no energy points" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ClapTrap attacks" << target << ", causing " << this->attackDamage << " points of damage!"<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->points == 0)
	{
		std::cout << "ClapTrap is already dead" << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap has no energy points" << std::endl;
		return ;
	}
	if (amount > this->points)
		this->points = 0;
	else
		this->points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->points == 0)
	{
		std::cout << "ClapTrap is already dead" << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap has no energy points" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	this->points += amount;
}