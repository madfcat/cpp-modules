/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:43:17 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/23 22:14:39 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		horde[i] = Zombie(name);
	}
	return (horde);
}