/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:42:39 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/26 14:18:40 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# ifndef WEAPON_HPP
#  include "Weapon.hpp"
# endif

class HumanA
{
	private:
		Weapon		&weapon;
		std::string	name;

	public:
		 void		attack() const;
		 HumanA(std::string name, Weapon &weapon);
};

#endif
