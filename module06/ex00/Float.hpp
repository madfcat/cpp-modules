/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:41:47 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/15 20:05:00 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include <cmath>

class Float
{
private:
	float value;

public:
	Float();
	Float(float value);
	Float(const Float &);
	Float &operator=(const Float &);
	~Float();

	float getValue() const;
};

std::ostream& operator<<(std::ostream &os, const Float &);
