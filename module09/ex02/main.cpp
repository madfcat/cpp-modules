/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:53:21 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/09 18:50:43 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	try
	{
		if (argc == 1)
		{
			PmergeMe::log("No arguments provided", ERROR);
			PmergeMe::log("Usage: ./PmergeMe <arg1> <arg2> ... <argN>", INFO);
			return EXIT_FAILURE;
		}

		PmergeMe mergeSelection(argv);
		mergeSelection.executeOnList();
		mergeSelection.executeOnVector();
	}
	catch (PmergeMe::Error& e)
	{
		PmergeMe::log(e.getMessage(), ERROR);
		return EXIT_FAILURE;
	}
	catch (std::exception& e)
	{
		PmergeMe::log(e.what(), ERROR);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}