/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:06:52 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/30 18:49:44 by vshchuki         ###   ########.fr       */
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

// Intern(const Intern& other);
// const Intern& operator=(const Intern& other);

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
	else
	{
		return nullptr;
	}
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

// Form*	Intern::makeShrubberyCreationForm(std::string formTarget)
// {
// 	return new ShrubberyCreationForm(formTarget);
// }

// Form*	Intern::makeRobotomyRequestForm(std::string formTarget)
// {
// 	return new RobotomyRequestForm(formTarget);
// }

// Form*	Intern::makePresidentialPardonForm(std::string formTarget)
// {
// 	return new PresidentialPardonForm(formTarget);
// }