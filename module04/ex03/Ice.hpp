/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:34 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/19 17:54:43 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"
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