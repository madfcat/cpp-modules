/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:42:34 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/04 17:29:26 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(nullptr), name(name)
{
	std::cout << this->name << " is being created." << std::endl;
}

void	HumanB::attack() const
{
	if (this->weapon)
	{
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	}
	else
		std::cout << this->name << " can not attack without a weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
