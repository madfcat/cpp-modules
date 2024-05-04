/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:43:01 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/04 17:30:54 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << "Weapon of type: \"" << this->type << "\" is being created." << std::endl;
}

std::string	Weapon::getType() const
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}