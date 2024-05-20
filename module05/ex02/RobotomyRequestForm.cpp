/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:31:31 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/20 20:32:20 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 145, 137)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 145, 137), target(target)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &other)
		this->isSigned = other.getIsSigned();
		
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

/**
 * Improve by using:
 * https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
*/
int	RobotomyRequestForm::executeAction() const
{
	if (std::rand() % 2 == 0)
		std::cout << "🤖 " + this->target + " has been robotomized successfully ✅" << std::endl;
	else
		std::cout << "🤖 " + this->target + " robotomy failed 🚫" << std::endl;

	return EXIT_SUCCESS;
}
