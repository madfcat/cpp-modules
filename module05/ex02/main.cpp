/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:51:20 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/22 13:45:14 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	{
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
	
	return 0;
}
