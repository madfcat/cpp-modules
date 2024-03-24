/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:42:39 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/24 21:13:00 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
# include "Weapon.hpp"
#endif

class HumanB
{
	private:
		Weapon	*weapon;
		std::string				name;

	public:
		HumanB(std::string name);
		//  ~HumanB();
		void					attack() const;
		void					setWeapon(Weapon &weapon);
};
