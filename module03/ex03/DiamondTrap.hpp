/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:17:50 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/25 21:52:17 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <iostream>
# ifndef SCAVTRAP_HPP
#  include "ScavTrap.hpp"
# endif
# ifndef FRAGTRAP_HPP
#  include "FragTrap.hpp"
# endif

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;

	public:
		DiamondTrap(std::string name);
		~DiamondTrap();

		void attack(std::string target);
		void whoAmI();
};

#endif