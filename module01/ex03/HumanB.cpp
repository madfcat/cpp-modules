/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:42:34 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/17 16:08:28 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(nullptr)
{
	this->name = name;
}

void	HumanB::attack() const
{
	if (this->weapon)
	{
		std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
	}
	else
		std::cout << this->name << " can not attack without a weapon" << "\n";
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
