/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:55:06 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/03 15:41:36 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name) : name(name), inventory{nullptr}
{
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& other) : name(other.name)
{
	for (int i = 0; i < this->inventorySize; i++)
	{
		delete (this->inventory[i]);
		if (other.inventory[i])
		 	inventory[i] = other.inventory[i]->clone();
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character assignment operator called" << std::endl;
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
	std::cout << "Character destructor called" << std::endl;
	
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (!m || this->inventory[this->inventorySize - 1])
		return ;
	for (int i = 0; i < this->inventorySize; i++)
	{
		if (!inventory[i])
		{
		 	inventory[i] = m->clone();
			return ;
		}
	}
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
	inventory[idx]->use(target);
}
