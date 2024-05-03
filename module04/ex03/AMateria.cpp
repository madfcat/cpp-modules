/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:47:37 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/03 16:04:09 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("default")
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
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