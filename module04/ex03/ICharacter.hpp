/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:32:13 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/02 16:30:27 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <iostream>
# ifndef AMATERIA_HPP
#  include "AMateria.hpp"
# endif

class ICharacter
{
	private:
		std::string name;
		static const int inventorySize = 4;
		AMateria *inventory[inventorySize];

	public:
		ICharacter(const std::string& name);
		ICharacter(const ICharacter& other);
		ICharacter& operator=(const ICharacter& other);

		virtual ~ICharacter() {};
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
		
};

#endif
