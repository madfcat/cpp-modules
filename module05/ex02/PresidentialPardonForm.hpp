/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:33:10 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/22 17:48:20 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target = "unknown";

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		const PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm() override;

		virtual int	executeAction() const override;
};

#endif