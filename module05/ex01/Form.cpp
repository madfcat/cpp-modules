/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:21:05 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/22 19:10:03 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
	std::cout << this->name << ": Form default constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute)
	: name(name), gradeToSign(gradeToSign), gradeToToExecute(gradeToExecute)
{
	std::cout << this->name << ": Form constructor called" << std::endl;
	if (gradeToSign > 150 || gradeToToExecute > 150)
		throw Form::GradeTooLowException();
	if (gradeToSign < 1 || gradeToToExecute < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& other): name(other.getName()), isSigned(other.getIsSigned()), gradeToSign(other.getGradeToSign()), gradeToToExecute(other.getGradeToExecute())
{
	std::cout << this->name << ": Form copy constructor called" << std::endl;

}

const Form& Form::operator=(const Form& other)
{
	std::cout << this->name << ": Form assignment operator called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << this->name << ": Form destructor called" << std::endl;

}

void		Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();

}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

unsigned int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

unsigned int Form::getGradeToExecute() const
{
	return this->gradeToToExecute;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "❗️ Invalid grade. Grade is too high.";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "❗️ Invalid grade. Grade is too low.";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Name: " << form.getName() << ", is signed: " << std::boolalpha << form.getIsSigned() << ", grade required to sign: " << form.getGradeToSign() << ", grade required to execute: " << form.getGradeToExecute();
	return os;
}