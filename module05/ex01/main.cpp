/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:53:35 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/22 14:10:20 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <memory>

int main()
{
	{
		std::cout << std::endl;
		std::cout << "====== Testing GradeTooLowException ======" << std::endl;
		std::cout << "== Testing gradeToSign GradeTooLowException" << std::endl;
		Form* form1 = nullptr;
		try
		{
			form1 = new Form("Form #1", 151, 10);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << form1 << std::endl;
		delete form1;

		std::cout << "== Testing gradeToExecute GradeTooLowException" << std::endl;
		std::shared_ptr<Form> form2;
		try
		{
			form2 = std::make_shared<Form>("Form #2", 150, 151);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << form2 << std::endl;

		std::cout << "== Testing gradeToSign GradeTooHighException" << std::endl;
		std::shared_ptr<Form> form3;
		try
		{
			form3 = std::make_shared<Form>("Form #3", 0, 10);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << form3 << std::endl;

		std::cout << "== Testing gradeToExecute GradeTooHighException" << std::endl;
		std::shared_ptr<Form> form4;
		try
		{
			form4 = std::make_shared<Form>("Form #4", 150, 151);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << form4 << std::endl;
	}
	{
		Bureaucrat travis = Bureaucrat("Travis", 10);
		Bureaucrat stewart = Bureaucrat("Stewart", 1);

		std::cout << std::endl;
		std::cout << "====== Copy Constructor test ======" << std::endl;
		Form form1("Form To Copy", 5, 5);
		std::cout << "== form1 be signed by Travis" << std::endl;
		try
		{
			form1.beSigned(travis);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "== Travis signs form1" << std::endl;
		try
		{
			travis.signForm(form1);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		Form form2 = form1;
		std::cout << "form2 - " << form2 << std::endl;

		std::cout << std::endl;
		std::cout << "====== Assignment operator test ======" << std::endl;
		Form form3("Form to assign", 4, 10);
		Form form4;
		std::cout << "== form3 be signed by Travis" << std::endl;
		try
		{
			form3.beSigned(travis);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "== Travis signs form3" << std::endl;
		try
		{
			travis.signForm(form3);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		form4 = form3;
		std::cout << "form4 - " << form4 << std::endl;
		std::cout << "== form3 be signed by Stewart" << std::endl;
		try
		{
			form3.beSigned(stewart);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "== Stewart signs form4" << std::endl;
		try
		{
			stewart.signForm(form4);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "form3 - " << form3 << std::endl;
		std::cout << "form4 - " << form4 << std::endl;
		std::cout << std::endl;
		std::cout << "== Destruction" << std::endl;
	}
}
