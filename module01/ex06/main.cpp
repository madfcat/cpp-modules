/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:14:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/25 20:29:16 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr << "Wrong arguments count" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}
