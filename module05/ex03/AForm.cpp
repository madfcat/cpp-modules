/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:21:05 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/22 14:15:01 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
{
	std::cout << this->name << ": AForm default costructor called" << std::endl;
}

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute)
	: name(name), gradeToSign(gradeToSign), gradeToToExecute(gradeToExecute)
{
	std::cout << this->name << ": AForm constructor called" << std::endl;
	if (gradeToSign > 150 || gradeToToExecute > 150)
		throw AForm::GradeTooLowException();
	if (gradeToSign < 1 || gradeToToExecute < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other): name(other.getName()), isSigned(other.getIsSigned()), gradeToSign(other.getGradeToSign()), gradeToToExecute(other.getGradeToExecute())
{
	std::cout << this->name << ": AForm copy costructor called" << std::endl;

}

const AForm& AForm::operator=(const AForm& other)
{
	std::cout << this->name << ": AForm assignment operator called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << this->name << ": AForm destructor called" << std::endl;

}

void		AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->isSigned = true;
	else
		throw AForm::GradeTooLowException();

}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::IsNotSignedException();
	else if (executor.getGrade() >= this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
		executeAction();
}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

unsigned int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

unsigned int AForm::getGradeToExecute() const
{
	return this->gradeToToExecute;
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "❗️ Invalid grade. Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "❗️ Invalid grade. Grade is too low.";
}

const char* AForm::IsNotSignedException::what() const noexcept
{
	return "❗️ Form is not signed.";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Name: " << form.getName() << ", is signed: " << std::boolalpha << form.getIsSigned() << ", grade required to sign: " << form.getGradeToSign() << ", grade required to execute: " << form.getGradeToExecute();
	return os;
}