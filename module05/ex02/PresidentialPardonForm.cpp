/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:31:50 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/23 16:02:29 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &other)
		this->isSigned = other.getIsSigned();

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

int	PresidentialPardonForm::executeAction() const
{
	std::cout << this->target + " has been pardoned by Zaphod Beeblebrox 📝" << std::endl;

	return EXIT_SUCCESS;
}
