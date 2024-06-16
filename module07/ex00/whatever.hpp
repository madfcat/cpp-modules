/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:52:11 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 18:07:37 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

template <typename T>
void swap(T& value1, T& value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;
}

template <typename T>
T min(T& value1, T& value2)
{
	if (value2 <= value1)
		return value2;
	return value1;
}

template <typename T>
T max(T& value1, T& value2)
{
	if (value2 >= value1)
		return value2;
	return value1;
}
