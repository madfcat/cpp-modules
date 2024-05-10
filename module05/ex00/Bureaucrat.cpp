/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:05 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/10 18:13:47 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

const std::string Bureaucrat::getName() const
{
	return this->name;
}

unsigned char Bureaucrat::getGrade() const
{
	return this->grade;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat)
{
	os << "<name> bureaucrat grade " << bureaucrat.getGrade();
	return os;
}