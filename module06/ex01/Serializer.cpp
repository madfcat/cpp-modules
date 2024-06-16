/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:29:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 16:07:28 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t raw = 0;
	std::memcpy(&raw, &ptr, sizeof(Data*));
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr = nullptr;
	std::memcpy(&ptr, &raw, sizeof(Data*));
	return ptr;
}
