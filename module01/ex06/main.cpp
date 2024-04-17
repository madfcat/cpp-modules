/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:14:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/17 17:04:19 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Wrong arguments count" << "\n";
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}
