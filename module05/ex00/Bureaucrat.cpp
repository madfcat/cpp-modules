/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:05 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/11 18:25:28 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::string Bureaucrat::getName() const
{
	return this->name;
}

unsigned char Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::GradeTooLowException()
{
	throw std::invalid_argument("Invalid grade. Grade is too low.");
}

void Bureaucrat::GradeTooHighException()
{
	throw std::invalid_argument("Invalid grade. Grade is too high.");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat)
{
	os << "<name> bureaucrat grade " << bureaucrat.getGrade();
	return os;
}