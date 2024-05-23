/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:51:20 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/23 18:00:09 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		std::cout << "====== ShrubberyCreationForm Copy Constructor======" << std::endl;
		ShrubberyCreationForm shrubbery = ShrubberyCreationForm("home");
		Bureaucrat mary("Mary", 15);
		std::cout << "shrubbery:" << std::endl;
		std::cout << shrubbery << std::endl;
		mary.signForm(shrubbery);
		std::cout << shrubbery << std::endl;
		std::cout << "== Calling copy constructor" << std::endl;
		ShrubberyCreationForm shrubbery2(shrubbery);
		std::cout << "shrubbery2: " << std::endl;
		std::cout << shrubbery2 << std::endl;
		std::cout << "== Calling assignment operator" << std::endl;
		ShrubberyCreationForm shrubbery3;
		shrubbery3 = shrubbery;
		std::cout << "shrubbery3:" << std::endl;
		std::cout << shrubbery3 << std::endl;
		std::cout << "== Destruction" << std::endl;
	}
	{
	std::cout << std::endl;
		std::cout << "====== Testing ShrubberyCreationForm ======" << std::endl;
		Bureaucrat john("John", 15);
		std::cout << john << std::endl;

		Bureaucrat michael("Michael", 149);
		std::cout << michael << std::endl;
		
		ShrubberyCreationForm shrubbery = ShrubberyCreationForm("home");
		std::cout << shrubbery << std::endl;
		michael.signForm(shrubbery);

		try
		{
			shrubbery.execute(michael);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		john.signForm(shrubbery);

		std::cout << shrubbery << std::endl;
		try
		{
			shrubbery.execute(michael);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			shrubbery.execute(john);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "====== Testing RobotomyRequestForm ======" << std::endl;
		Bureaucrat john("John", 15);
		std::cout << john << std::endl;

		Bureaucrat michael("Michael", 149);
		std::cout << michael << std::endl;
		
		RobotomyRequestForm robotomy = RobotomyRequestForm("Enemy #1");
		std::cout << robotomy << std::endl;
		michael.signForm(robotomy);
		
		try
		{
			robotomy.execute(michael);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		john.signForm(robotomy);

		std::cout << robotomy << std::endl;
		try
		{
			robotomy.execute(michael);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			robotomy.execute(john);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "====== Testing PresidentialPardonForm ======" << std::endl;
		Bureaucrat john("John", 4);
		std::cout << john << std::endl;

		Bureaucrat michael("Michael", 26);
		std::cout << michael << std::endl;
		
		PresidentialPardonForm pardon = PresidentialPardonForm("Enemy #1");
		std::cout << pardon << std::endl;

		michael.signForm(pardon);

		michael.executeForm(pardon);
		try
		{
			pardon.execute(michael);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		john.signForm(pardon);

		std::cout << pardon << std::endl;
		try
		{
			pardon.execute(michael);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			pardon.execute(john);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		michael.executeForm(pardon);
		john.executeForm(pardon);
	}
	
	return 0;
}
