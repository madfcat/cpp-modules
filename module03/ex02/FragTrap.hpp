/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:39:20 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/06 15:40:28 by vshchuki         ###   ########.fr       */
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
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap &other);
		~FragTrap();
		void highFivesGuys(void);
};

#endif