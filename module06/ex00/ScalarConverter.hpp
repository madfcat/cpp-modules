/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:24:56 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/15 21:42:09 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
// #include <limits>
// #include <cctype>
#include <iostream>
#include <cmath>
#include "Helper.hpp"
// #include "Double.hpp"
// #include "Float.hpp"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &) = delete;
		ScalarConverter &operator=(const ScalarConverter &) = delete;
		ScalarConverter(ScalarConverter &&) = delete;
		ScalarConverter &operator=(ScalarConverter &&) = delete;
		~ScalarConverter() = delete;

	public:
		static void convert(std::string str);
};
