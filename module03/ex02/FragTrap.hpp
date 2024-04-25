/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:39:20 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/25 16:31:23 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# ifndef CLAPTRAP_HPP
#  include "ClapTrap.hpp"
# endif

class FragTrap: public ClapTrap
{
	public:
		using ClapTrap::ClapTrap;
		FragTrap(std::string name);
		~FragTrap();
		void highFivesGuys(void);
};

#endif