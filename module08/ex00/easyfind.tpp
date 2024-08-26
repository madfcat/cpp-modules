/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:26:05 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/26 16:02:02 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
int easyfind(T container, int value)
{
	typename T::iterator it = find(container.begin(), container.end(), value);
	if (it != container.end())
		return *it;
	throw std::runtime_error("Value not found");
}
