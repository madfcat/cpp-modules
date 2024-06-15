/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:41:53 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/15 20:56:36 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Double
{
private:
	double value;

public:
	Double();
	Double(double value);
	Double(const Double &);
	Double &operator=(const Double &);
	~Double();

	double getValue() const;
};

std::ostream& operator<<(std::ostream &os, const Double &);
