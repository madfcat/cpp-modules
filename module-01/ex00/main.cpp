/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:43:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/23 22:03:04 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// #include <string>

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
	Zombie *someZombie;

	someZombie = newZombie("George");
	(*someZombie).announce();
	delete someZombie;
	
	randomChump("Nicolas");
	return (0);
}