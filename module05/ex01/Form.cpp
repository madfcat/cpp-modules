/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:21:05 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/12 20:57:42 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
	std::cout << this->name << ": Form default costructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToToExecute(gradeToExecute)
{
	std::cout << this->name << ": Form costructor called" << std::endl;
}

Form::Form(const Form& other): name(other.getName()), isSigned(other.getIsSigned()), gradeToSign(other.getGradeToSign()), gradeToToExecute(other.getGradeToExecute())
{
	std::cout << this->name << ": Form copy costructor called" << std::endl;

}

// Form assignment operator

Form::~Form()
{
	std::cout << this->name << ": Form destructor called" << std::endl;

}


std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Name: " << form.getName() << ", is signed: " << form.getIsSigned() << ", grade required to sign: " << form.getGradeToSign() << ", grade required to execute: " << form.getGradeToExecute();
	return os;
}