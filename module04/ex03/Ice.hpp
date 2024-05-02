/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:34 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/02 16:00:06 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# ifndef AMATERIA_HPP
#  include "AMateria.hpp"
# endif
# ifndef ICHARACTER_HPP
#  include "ICharacter.hpp"
# endif

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice* other);
		Ice& operator=(const Ice& other);
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif