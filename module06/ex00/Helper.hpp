/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:53:46 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 13:45:30 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

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
		static std::string	detectType(std::string str);
		static std::string	convert_char(char c);
		static bool 		isValidPointNummber(std::string &str, bool isFloat = true);
		template <typename T>
		static void 		printOutput(const T &value, std::string type = "unset", std::string str = "unset");
};

// // Explicit instantiation for necessary types
// // This ensures the compiler generates the function for these types
extern template void Helper::printOutput(const char&, std::string, std::string);
extern template void Helper::printOutput(const int&, std::string, std::string);
extern template void Helper::printOutput(const float&, std::string, std::string);
extern template void Helper::printOutput(const double&, std::string, std::string);
