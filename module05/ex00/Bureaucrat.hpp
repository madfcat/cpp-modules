/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:08 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/11 20:44:31 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{
	private:
		const std::string	name;
		unsigned char		grade;

	public:
		const std::string getName() const;
		unsigned char getGrade() const;
		void incrementGrade();
		void decrementGrade();

		GradeTooHighException;
		GradeTooLowException;
};

#endif