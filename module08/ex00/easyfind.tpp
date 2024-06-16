/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:26:05 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/17 01:24:54 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
int easyfind(T container, int value)
{
	for (int num : container)
	{
		if (num == value)
			return num;
	}
	throw std::runtime_error("Value not found");
}
