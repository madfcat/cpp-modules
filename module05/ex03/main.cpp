/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:51:20 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 13:23:14 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		std::cout << "=== Robotomy Request Form ===" << std::endl;
		
		Intern joe;
		Form*   rrf;

		rrf = joe.makeForm("robotomy request", "Bender");
		std::cout << "Grade to execute: " << rrf->getGradeToExecute() << std::endl;
		std::cout << "Grade to sign: " << rrf->getGradeToSign() << std::endl;
		std::cout << "Is signed: " << std::boolalpha << rrf->getIsSigned() << std::endl;

		delete rrf;
	}
	{
		std::cout << std::endl;
		std::cout << "=== Shrubbery Creation Form ===" << std::endl;

		Bureaucrat michael("Michael", 1);
		Intern john;
		Form*   scf;

		std::cout << michael << std::endl;
		scf = john.makeForm("shrubbery creation", "Bender");
		std::cout << "Grade to execute: " << scf->getGradeToExecute() << std::endl;
		std::cout << "Grade to sign: " << scf->getGradeToSign() << std::endl;
		std::cout << "Is signed: " << std::boolalpha << scf->getIsSigned() << std::endl;
		michael.signForm(*scf);
		std::cout << "Is signed: " << std::boolalpha << scf->getIsSigned() << std::endl;

		delete scf;
	}
	{
		std::cout << std::endl;
		std::cout << "=== More tests ===" << std::endl;

		Bureaucrat michael("Michael", 146);
		Intern john;
		Form*   ppf;

		std::cout << michael << std::endl;
		ppf = john.makeForm("shrubbery creation", "Bender");
		std::cout << "Grade to execute: " << ppf->getGradeToExecute() << std::endl;
		std::cout << "Grade to sign: " << ppf->getGradeToSign() << std::endl;
		std::cout << "Is signed: " << std::boolalpha << ppf->getIsSigned() << std::endl;
		michael.signForm(*ppf);
		std::cout << "Is signed: " << std::boolalpha << ppf->getIsSigned() << std::endl;

		delete ppf;
	}
}
