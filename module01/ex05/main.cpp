/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:14:15 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/28 18:42:43 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	test(Harl &harl, std::string level)
{
	std::cout << "Testing " << level << ":" << std::endl;
	harl.complain(level);
	std::cout << std::endl;
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
