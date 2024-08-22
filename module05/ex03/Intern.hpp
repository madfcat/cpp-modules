/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:07:03 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/22 14:29:14 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>
# include <string>
# include <memory>

using Form = AForm;
using FactoryFunction = std::unique_ptr<Form>(*)(std::string target);

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
};

#endif