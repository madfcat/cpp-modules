/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:25:25 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/25 15:45:01 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char const *argv[])
{
	std::ifstream	file;
	std::string		content;

	if (argc != 4)
		return (Replacer::outputError("Error: Wrong input!"));
		
	if (std::string(argv[1]) == "" || std::string(argv[2]) == "" || std::string(argv[3]) == "")
		return (Replacer::outputError("Error: Empty arguments are not supported!"));

	file.open(argv[1]);
	if (!file)
		return (Replacer::outputError("Error: File could not be opened!"));

	content = Replacer::readFileIntoString(file);
	file.close();

	Replacer::replaceAll(content, std::string(argv[2]), std::string(argv[3]));

	std::ofstream outfile(std::string(argv[1]) + ".replace");
	if (!outfile)
		return (Replacer::outputError("Error: Not possible to write to the file!"));
	outfile << content;
	outfile.close();
	return (0);
}
