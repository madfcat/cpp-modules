/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:32:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/01 14:54:15 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter(const std::string &name) : name(name)
{
	std::cout << "ICharacter constructor called" << std::endl;
}

std::string const & ICharacter::getName() const
{
	return (this->name);
}


void ICharacter::use(int idx, ICharacter& target)
{

}