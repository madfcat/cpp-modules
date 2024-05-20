/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:40:33 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/20 20:07:36 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain())
{
	for (int i = 0; i < 100; i++)
	{
		this->brain->setIdea(i, other.brain->getIdea(i));
	}
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		delete (this->brain);
		this->brain = new Brain();
		
		Animal::operator=(other);
		for (int i = 0; i < 100; i++)
			this->brain->setIdea(i, other.brain->getIdea(i));
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->type << " makes sound: Woof" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return (this->brain);
}
