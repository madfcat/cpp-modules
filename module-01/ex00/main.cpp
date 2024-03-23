/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:43:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/23 18:56:30 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

void randomChump( std::string name );

void createAnotherStackZombie()
{
	Zombie anotherStackZombie("John");
	anotherStackZombie.announce();
}

int main(void)
{
	Zombie someZombie("George");
	someZombie.announce();

	createAnotherStackZombie();
	
	randomChump("Nicolas");
	return (0);
}