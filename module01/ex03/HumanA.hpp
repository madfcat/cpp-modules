/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:42:39 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/05 16:46:56 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# ifndef WEAPON_HPP
#  include "Weapon.hpp"
# endif
# include <iostream>
# include <string>

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
