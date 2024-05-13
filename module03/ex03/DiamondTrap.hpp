/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:17:50 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/13 19:53:46 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <iostream>
# include <string>
# ifndef SCAVTRAP_HPP
#  include "ScavTrap.hpp"
# endif
# ifndef FRAGTRAP_HPP
#  include "FragTrap.hpp"
# endif

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
	private:
		std::string name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap &other);
		~DiamondTrap();

		void attack(std::string target);
		void whoAmI();
};

#endif