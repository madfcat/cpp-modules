/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:27 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/03 16:05:23 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() + "’s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure());
}