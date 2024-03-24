/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:43:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/23 20:58:54 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int main(void)
{
	int NUMBER_OF_ZOMBIES = 15;

	Zombie* horde = zombieHorde(NUMBER_OF_ZOMBIES, "Boomer");
	for (int i = 0; i < NUMBER_OF_ZOMBIES; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
