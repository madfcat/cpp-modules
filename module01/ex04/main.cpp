/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:25:25 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/25 02:51:33 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	outputError(std::string message)
{
		std::cerr << message << std::endl;
		return (1);
}

std::string readFileIntoString(std::ifstream &file)
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

void replaceAll(std::string &str, std::string s1, std::string s2)
{
	size_t pos = 0;
	std::string str_copy = str;
	std::string result = "";
	while((pos = str_copy.find(s1, 0)) != std::string::npos)
	{
		result += str_copy.substr(0, pos) + s2;
		pos = pos + s1.length();
		str_copy = str_copy.substr(pos, str_copy.length() - pos);
	}

	str = result + str_copy;
}

int main(int argc, char const *argv[])
{
	std::ifstream	file;
	std::string		content;

	if (argc != 4)
		return (outputError("Error: Wrong input!"));
		
	if (std::string(argv[1]) == "" || std::string(argv[2]) == "" || std::string(argv[3]) == "")
		return (outputError("Error: Empty arguments are not supported!"));

	file.open(argv[1]);
	if (!file)
		return (outputError("Error: File could not be opened!"));

	content = readFileIntoString(file);
	file.close();

	replaceAll(content, std::string(argv[2]), std::string(argv[3]));

	std::ofstream outfile(std::string(argv[1]) + ".replace");
	if (!outfile)
		return (outputError("Error: Not possible to write to the file!"));
	outfile << content;
	outfile.close();
	return (0);
}
