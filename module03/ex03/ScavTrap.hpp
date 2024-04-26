/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:43:03 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/26 12:02:10 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# ifndef CLAPTRAP_HPP
#  include "ClapTrap.hpp"
# endif

class ScavTrap: public ClapTrap
{
	public:
		// using ClapTrap::ClapTrap;
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=(const ScavTrap &other);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};

#endif