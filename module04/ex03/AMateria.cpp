/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:47:37 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/07 18:00:40 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("default")
{
	std::cout << "Type " << this->getType() << ": AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
	std::cout << "Type " << this->getType() << ": AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "Type " << this->getType() << ": AMateria assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Type " << this->getType() << ": AMateria destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria used " << target.getName() << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}