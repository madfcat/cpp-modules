/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:42:39 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/05 16:47:01 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# ifndef WEAPON_HPP
#  include "Weapon.hpp"
# endif
# include <iostream>
# include <string>

class HumanB
{
	private:
		Weapon	*weapon;
		std::string				name;

	public:
		HumanB(std::string name);
		void					attack() const;
		void					setWeapon(Weapon &weapon);
};

#endif