/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:23:57 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/25 15:43:44 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

class Replacer
{
	public: 
		static std::string	readFileIntoString(std::ifstream &file);
		static void			replaceAll(std::string &str, std::string s1, std::string s2);
		static int			outputError(std::string message);
};
