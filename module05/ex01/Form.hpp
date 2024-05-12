/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:21:02 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/12 20:46:59 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <stdexcept>

class Form
{
	private:
		const std::string	name = "Unknown";
		bool				isSigned = false;
		const int			gradeToSign = 150;
		const int			gradeToToExecute = 150; 
	
	public:
		Form();
		Form(const Form& other);
		const Form& operator=(const Form& other);
		~Form();

		Form(std::string name, int gradeToSign, int gradeToExecute);

		const std::string	getName() const;
		bool				getIsSigned() const;
		const int			getGradeToSign() const;
		const int			getGradeToExecute() const;

		class GradeTooHighException: std::exception
		{
			const char* what() const noexcept override;
		};

		class GradeTooLowException: std::exception
		{
			const char* what() const noexcept override;
		};
		
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
