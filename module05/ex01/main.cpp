/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:53:35 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/13 19:43:56 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << std::endl;
		std::cout << "====== Testing GradeTooLowException ======" << std::endl;
		Bureaucrat* johnny = nullptr;
		try
		{
			johnny = new Bureaucrat("Johnny", 151);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << johnny << std::endl;
		delete johnny;
	}
	{
		std::cout << std::endl;
		std::cout << "====== Testing GradeTooHighException ======" << std::endl;
		Bureaucrat* mary = nullptr;
		try
		{
			new Bureaucrat("Mary", 0);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << mary << std::endl;
		delete mary;
	}
	{
		std::cout << std::endl;
		std::cout << "====== Testing Shared pointers / decrement exception ======" << std::endl;
		std::shared_ptr<Bureaucrat> jessica = std::make_shared<Bureaucrat>();
		try
		{
			jessica->decrementGrade();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << *jessica << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "====== Testing stack object / increment exception ======" << std::endl;
		Bureaucrat helga("Helga", 1);
		try
		{
			helga.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << helga << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "====== Copy Constructor test ======" << std::endl;
		Bureaucrat helga("Helga", 4);
		Bureaucrat helga2 = helga;
	}
	{
		std::cout << std::endl;
		std::cout << "====== Assignment operator test ======" << std::endl;
		Bureaucrat george("George", 4);
		Bureaucrat george2;
		george2 = george;
	}
}
