/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:53:46 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/15 21:55:28 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Double.hpp"
#include "Float.hpp"

class Helper
{
	private:
		Helper();
		Helper(const Helper &) = delete;
		Helper &operator=(const Helper &) = delete;
		Helper(Helper &&) = delete;
		Helper &operator=(Helper &&) = delete;
		~Helper() = delete;

	public:
		static std::string detect_type(std::string str);
		static std::string convert_char(char c);

		template <typename T>
		static void printOutput(const T &value, std::string type = "unset");
};

// // Explicit instantiation for necessary types
// // This ensures the compiler generates the function for these types
extern template void Helper::printOutput(const char&, std::string);
extern template void Helper::printOutput(const int&, std::string);
extern template void Helper::printOutput(const float&, std::string);
extern template void Helper::printOutput(const double&, std::string);