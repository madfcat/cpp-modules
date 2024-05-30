/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:51:20 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/30 19:07:29 by vshchuki         ###   ########.fr       */
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
		Intern joe;
		Form*   rrf;
		rrf = joe.makeForm("robotomy request", "Bender");

		std::cout << rrf->getGradeToExecute() << std::endl;
		std::cout << rrf->getGradeToSign() << std::endl;
		std::cout << rrf->getIsSigned() << std::endl;

		delete rrf;
	}
	
	return 0;
}
