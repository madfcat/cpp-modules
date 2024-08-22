/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:31:37 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/22 18:51:14 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getIsSigned(), other.getGradeToSign(), other.getGradeToExecute())
{
	this->target = other.target;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

int	ShrubberyCreationForm::executeAction() const
{
	std::ofstream shrubberyFile(this->target + "_shrubbery");
	if (!shrubberyFile.is_open()) {
		std::cout << "Error: Unable to create shrubbery file!" << std::endl;
		return EXIT_FAILURE;
	}

	shrubberyFile << "              ,@@@@@@@," << std::endl;
	shrubberyFile << "     ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	shrubberyFile << "  ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	shrubberyFile << " ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	shrubberyFile << " %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	shrubberyFile << " %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	shrubberyFile << " `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	shrubberyFile << "     |o|        | |         | |" << std::endl;
	shrubberyFile << "     |.|        | |         | |" << std::endl;
	shrubberyFile << "__\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

	std::cout << "🌳 " + this->target + "_shrubbery file created" << std::endl;

	return EXIT_SUCCESS;
}
