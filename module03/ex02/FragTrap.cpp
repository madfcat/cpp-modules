/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:36:42 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/25 15:56:15 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << this->name << ": FragTrap constructor called." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << this->name << ": FragTrap destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->name << ": FragTrap requests a high five!" << std::endl;
}