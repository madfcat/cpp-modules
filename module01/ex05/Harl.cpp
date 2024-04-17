/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:53:36 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/17 16:08:28 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->levels[0] = "DEBUG";
	this->functions[0] = &Harl::debug;

	this->levels[1] = "INFO";
	this->functions[1] = &Harl::info;

	this->levels[2] = "WARNING";
	this->functions[2] = &Harl::warning;

	this->levels[3] = "ERROR";
	this->functions[3] = &Harl::error;
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << "\n";
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << "\n";
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << "\n";
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << "\n";
}

void    Harl::complain( std::string level )
{	
	(this->func) = this->getFunction(level);
	if (this->func)
	{
		(this->*func)();
		return ;
	}
	std::cout << "There is no such level as " << level << "\n";
}

Harl::MemberFunction Harl::getFunction(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->levels[i] == level)
			return (this->functions[i]);
	}
	return (nullptr);
}