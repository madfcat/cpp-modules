/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:23:59 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/17 16:08:28 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int	Replacer::outputError(std::string message)
{
		std::cerr << message << "\n";
		return (1);
}

std::string Replacer::readFileIntoString(std::ifstream &file)
{
	std::string	content;
	std::string	line;

	while (std::getline(file, line))
	{
		content += line;
		
		if (!file.eof())
			content += '\n';
	}
	return (content);
}

void Replacer::replaceAll(std::string &str, std::string s1, std::string s2)
{
	size_t 		pos = 0;
	std::string	str_copy = str;
	std::string	result = "";
	
	while((pos = str_copy.find(s1, 0)) != std::string::npos)
	{
		result += str_copy.substr(0, pos) + s2;
		pos = pos + s1.length();
		str_copy = str_copy.substr(pos, str_copy.length() - pos);
	}

	str = result + str_copy;
}