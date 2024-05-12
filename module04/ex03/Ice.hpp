/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:34 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/12 02:24:25 by vshchuki         ###   ########.fr       */
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
# include <iostream>

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		virtual ~Ice() override;

		virtual AMateria*	clone() const override;
		virtual void		use(ICharacter& target) override;
};

#endif