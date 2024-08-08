/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:04:19 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/08 20:20:40 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	try
	{
		if (argc != 2)
		{
			RPN::log("No expression provided", ERROR);
			RPN::log("Usage: ./RPN <RPN expression>", INFO);
			return EXIT_FAILURE;
		}

		RPN revPolishNotation(argv[1]);
		revPolishNotation.execute(" ");
	}
	catch (RPN::Error& e)
	{
		RPN::log(e.getMessage(), ERROR);
		return EXIT_FAILURE;
	}
	catch (std::exception& e)
	{
		RPN::log(e.what(), ERROR);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
