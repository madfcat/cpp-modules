/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:28:23 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/17 17:23:31 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
	private:
		int	points;
		int energyPoints;
		int attackDamage;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap& clapTrap);
		ClapTrap& operator=(const ClapTrap& otherClapTrap);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
