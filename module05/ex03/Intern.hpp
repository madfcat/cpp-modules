/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:07:03 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/30 18:47:04 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>
# include <string>

using Form = AForm;
using FactoryFunction = std::unique_ptr<Form>(*)(std::string target);
// using FactoryFunction = Form* (*)(std::string target);

class Intern
{
	private:
		static const int	FormCount = 3;
		FactoryFunction		factoryArray[FormCount];
		std::string			formNameArray[FormCount];

	public:
		Intern();
		Intern(const Intern& other);
		const Intern& operator=(const Intern& other);
		~Intern();

		Form*			makeForm(std::string formName, std::string formTarget);
		FactoryFunction getFunction(std::string formName);
		// Form*			makeShrubberyCreationForm(std::string formTarget);
		// Form*			makeRobotomyRequestForm(std::string formTarget);
		// Form*			makePresidentialPardonForm(std::string formTarget);
};

#endif