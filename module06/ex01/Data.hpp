/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:44:26 by vshchuki          #+#    #+#             */
/*   Updated: 2024/06/16 16:07:33 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Data
{
	private:
		int intNum = 0;
		std::string str;
		char charNum = 'A';

	public:
		Data();
		Data(int intNum, std::string str, char charNum);
		Data(const Data &other);
		Data& operator=(const Data &other);
		~Data();

		void printData();
};
