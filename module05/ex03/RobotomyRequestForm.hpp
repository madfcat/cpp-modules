/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:31:28 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/22 13:34:03 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
# include "AForm.hpp"
# include <random>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target = "unknown";

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		const RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm() override;

		virtual int	executeAction() const override;
};

#endif