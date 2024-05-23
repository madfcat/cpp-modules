/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:21:02 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/23 15:52:08 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name = "Unknown";
		bool				isSigned = false;
		const unsigned int	gradeToSign = 150;
		const unsigned int	gradeToToExecute = 150; 
	
	public:
		Form();
		Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		Form(const Form& other);
		const Form& operator=(const Form& other);
		~Form();
		
		void			beSigned(Bureaucrat& bureaucrat);

		std::string		getName() const;
		bool			getIsSigned() const;
		unsigned int	getGradeToSign() const;
		unsigned int	getGradeToExecute() const;

	private:
		class GradeTooHighException: public std::exception
		{
			const char* what() const noexcept override;
		};

		class GradeTooLowException: public std::exception
		{
			const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
