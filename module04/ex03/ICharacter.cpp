/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:32:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/02 17:29:59 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter(const std::string &name) : name(name), inventory{nullptr}
{
	std::cout << "ICharacter constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter& other) : name(other.name)
{
	for (int i = 0; i < this->inventorySize; i++)
	{
		delete (this->inventory[i]);
		// if (other.inventory[i])
		// 	inventory[i] = other.inventory[i]->clone();
	}
	std::cout << "ICharacter copy constructor called" << std::endl;
}

std::string const & ICharacter::getName() const
{
	return (this->name);
}

void ICharacter::use(int idx, ICharacter& target)
{
	inventory[idx]->use(target);
}