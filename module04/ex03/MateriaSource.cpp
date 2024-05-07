/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:51:56 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/07 19:34:49 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): storage{nullptr}
{
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < this->storageSize; i++)
	{
		delete (this->storage[i]);
		if (other.storage[i])
			this->storage[i] = other.storage[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	for (int i = 0; i < this->storageSize; i++)
	{
		delete (this->storage[i]);
		if (other.storage[i])
			this->storage[i] = other.storage[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < this->storageSize; i++)
		delete (this->storage[i]);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < this->storageSize; i++)
	{
		if (!this->storage[i])
		{
			std::cout << "Learned " << m->getType() << std::endl;
			this->storage[i] = m;
			return ;
		}
	}
	std::cout << "Storage is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->storageSize; i++)
	{
		if (this->storage[i] && this->storage[i]->getType() == type)
		{
			std::cout << "Created " << type << std::endl;
			return (this->storage[i]->clone());
		}
	}
	std::cout << "Materia type is unknown" << std::endl;
	return (nullptr);
}
