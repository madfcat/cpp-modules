/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:05 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/23 16:12:01 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << this->name << ": Bureaucrat default costructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): name(name), grade(grade)
{
	std::cout << this->name << ": Bureaucrat costructor called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << this->name << ": Bureaucrat copy costructor called" << std::endl;
	this->name = other.getName();
	this->grade = other.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << this->name << ": Bureaucrat assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.getName();
		this->grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->name << ": Bureaucrat destructor called" << std::endl;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == this->HighestGrade)
	{
		std::cout << "Highest grade can not be incremented" << std::endl;
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->grade--;
}
void Bureaucrat::decrementGrade()
{
	if (this->grade == this->LowestGrade)
	{
		std::cout << "Lowest grade can not be decremented" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	else
		this->grade++;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() + " signed " + form.getName()<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
		try
		{
			form.execute(*this);
			std::cout << this->getName() + " executed " + form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << this->getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
		}
}

const std::string Bureaucrat::getName() const
{
	return this->name;
}

unsigned int Bureaucrat::getGrade() const
{
	return this->grade;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "❗️ Invalid grade. Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "❗️ Invalid grade. Grade is too low.";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
