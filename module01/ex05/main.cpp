/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:14:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/17 16:08:28 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	test(Harl &harl, std::string level)
{
	std::cout << "Testing " << level << ":" << "\n";
	harl.complain(level);
	std::cout << "\n";
}

int	main(void)
{
	Harl harl;

	test(harl, "DEBUG");
	test(harl, "INFO");
	test(harl, "WARNING");
	test(harl, "ERROR");
	test(harl, "HELLO");

	return (0);
}
