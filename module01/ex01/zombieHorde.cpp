/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:43:17 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/05 14:58:12 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 *  Uses placement new instead of assignment operator to avoid calling the destructor.
*/
Zombie*	zombieHorde( int N, std::string name )
{
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		new(&horde[i]) Zombie(name);
	}
	return (horde);
}