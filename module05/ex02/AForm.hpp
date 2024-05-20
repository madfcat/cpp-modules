/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:21:02 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/20 20:13:34 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	name = "Unknown";
		bool				isSigned = false;
		const unsigned int	gradeToSign = 150;
		const unsigned int	gradeToToExecute = 150; 
	
	public:
		AForm();
		AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		AForm(const AForm& other);
		const AForm& operator=(const AForm& other);
		virtual ~AForm();
		
		void			beSigned(Bureaucrat& bureaucrat);

		std::string		getName() const;
		bool			getIsSigned() const;
		unsigned int	getGradeToSign() const;
		unsigned int	getGradeToExecute() const;


		class GradeTooHighException: public std::exception
		{
			const char* what() const noexcept override;
		};

		class GradeTooLowException: public std::exception
		{
			const char* what() const noexcept override;
		};

		class IsNotSignedException: public std::exception
		{
			const char* what() const noexcept;
		};
		void			execute(Bureaucrat const & executor) const;

	protected:
		virtual int		executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
