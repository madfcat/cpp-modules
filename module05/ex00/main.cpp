/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:53:35 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/22 13:06:29 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <memory>

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
		helga2.incrementGrade();
		std::cout << "Helga2 grade: " << helga2.getGrade() << std::endl;
		std::cout << "Helga grade: " << helga.getGrade() << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "====== Assignment operator test ======" << std::endl;
		Bureaucrat george("George", 4);
		Bureaucrat george2;
		std::cout << "George2 grade: " << george2.getGrade() << std::endl;
		george2 = george;
		george2.decrementGrade();
		std::cout << "George2 grade after assignment and decrement: " << george2.getGrade() << std::endl;
		std::cout << "George grade: " << george.getGrade() << std::endl;
	}
}
