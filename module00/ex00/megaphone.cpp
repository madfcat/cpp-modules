/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:51:17 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/04 15:53:40 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void convertToUpperCase(char *str)
{
	int i = 0;

	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	int i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	while (argv[i])
	{
		convertToUpperCase(argv[i]);
		std::cout << argv[i];
		i++;
	}
	std::cout << std::endl;

	return (0);
}

