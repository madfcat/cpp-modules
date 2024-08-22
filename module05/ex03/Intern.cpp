/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:06:52 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/22 18:57:31 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called"<< std::endl;	
	
	this->formNameArray[0] = "shrubbery creation";
	this->factoryArray[0] = [](std::string formTarget) -> std::unique_ptr<Form> {
		return std::make_unique<ShrubberyCreationForm>(formTarget);
	};

	this->formNameArray[1] = "robotomy request";
	this->factoryArray[1] = [](std::string formTarget) -> std::unique_ptr<Form> {
		return std::make_unique<RobotomyRequestForm>(formTarget);
	};

	this->formNameArray[2] = "presidential pardon";
	this->factoryArray[2] = [](std::string formTarget) -> std::unique_ptr<Form> {
		return std::make_unique<PresidentialPardonForm>(formTarget);
	};
}

Intern::Intern(const Intern& other): Intern()
{
	std::cout << "Intern copy constructor called"<< std::endl;	
	for (int i = 0; i < FormCount; i++)
	{
		this->formNameArray[i] = other.formNameArray[i];
		this->factoryArray[i] = other.factoryArray[i];
	}
}
const Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern assignment operator called"<< std::endl;	

	for (int i = 0; i < FormCount; i++)
	{
		this->formNameArray[i] = other.formNameArray[i];
		this->factoryArray[i] = other.factoryArray[i];
	}

	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called"<< std::endl;
}

Form*	Intern::makeForm(std::string formName, std::string formTarget)
{

	FactoryFunction f = this->getFunction(formName);
	if (f)
	{
		std::cout << "Intern creates " + formName << std::endl;
		return f(formTarget).release();
	}
	std::cout << formName << " does not exist" << std::endl;
	return nullptr;
}

FactoryFunction Intern::getFunction(std::string formTarget)
{
	for (int i = 0; i < this->FormCount; i++)
	{
		if (this->formNameArray[i] == formTarget)
			return factoryArray[i];
	}

	return nullptr;
}
