/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:55:06 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/09 20:47:46 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Unknown"), inventory{nullptr}
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string &name) : name(name), inventory{nullptr}
{
	std::cout << this->getName() << ": Character constructor called" << std::endl;
	// std::cout << this->inventory[0] << std::endl;
	// std::cout << this->inventory[1] << std::endl;
	// std::cout << this->inventory[2] << std::endl;
	// std::cout << this->inventory[3] << std::endl;
}

Character::Character(const Character& other) : name(other.name)
{
	std::cout << this->getName() + ": Character copy constructor called" << std::endl;
	// 	std::cout << this->inventory[0] << std::endl;
	// 	std::cout << this->inventory[1] << std::endl;
	// 	std::cout << this->inventory[2] << std::endl;
	// 	std::cout << this->inventory[3] << std::endl;
	for (int i = 0; i < this->inventorySize; i++)
	{
		// Character *ptr = nullptr;
		// std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		// std::cout << this->name << std::endl;
		// std::cout << ptr << std::endl;
		// std::cout << this->inventory[i] << std::endl;
		// std::cout << (*this->inventory[i]).getType() << std::endl;
		// if (this->inventory[i])
		// {
		// 	std::cout << "here" << std::endl;
		// 	delete (this->inventory[i]);
		// 	this->inventory[i] = nullptr;
		// }
		if (other.inventory[i])
		 	inventory[i] = other.inventory[i]->clone();
	}
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
			this->inventory[i] = nullptr;
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << this->getName() + ": Character destructor called" << std::endl;
	for (int i = 0; i < this->inventorySize; i++)
	{
		if (this->inventory[i] != nullptr)
		{
			delete (this->inventory[i]);
			this->inventory[i] = nullptr;
		}
	}
	
}

std::string const & Character::getName() const
{
	return (this->name);
}

/**
 * Equip a Materia to the character’s inventory.
 * It will clone the Materia and deete the Materia passed as a argument.
*/
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
			delete (m);
			m = nullptr;
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

AMateria* Character::getInventory(int idx) const
{
	if (idx < 0 || idx >= this->inventorySize)
		return (nullptr);
	return (this->inventory[idx]);
}
