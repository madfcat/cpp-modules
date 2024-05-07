/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:55:06 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/07 19:32:40 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name) : name(name), inventory{nullptr}
{
	std::cout << this->getName() << ": Character constructor called" << std::endl;
}

Character::Character(const Character& other) : name(other.name)
{
	for (int i = 0; i < this->inventorySize; i++)
	{
		delete (this->inventory[i]);
		if (other.inventory[i])
		 	inventory[i] = other.inventory[i]->clone();
	}
	std::cout << this->getName() + ": Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	std::cout << this->getName() + ": Character assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < this->inventorySize; i++)
		{
			delete (this->inventory[i]);
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < this->inventorySize; i++)
		delete (this->inventory[i]);
	std::cout << this->getName() + ": Character destructor called" << std::endl;
	
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < this->inventorySize; i++)
	{
		if (!inventory[i])
		{
			std::cout << this->getName() + " equipped " + m->getType() + " to inventory slot: " << i << std::endl;
		 	inventory[i] = m->clone();
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

/**
 * Handle the Materias your character left on the floor as you like.
Save the addresses before calling unequip(), or anything else, but
don’t forget that you have to avoid memory leaks.
The unequip() member function must NOT delete the Materia!
*/
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->inventorySize || !inventory[idx])
		return ;
	inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->inventorySize || !inventory[idx])
	{
		std::cout << "Invalid inventory slot" << std::endl;
		return ;
	}
	std::cout << this->getName() + " used " + inventory[idx]->getType() + " from inventory slot: " << idx << " on " << target.getName() << std::endl;
	inventory[idx]->use(target);
}
