/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:23 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/02 15:47:59 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# ifndef AMATERIA_HPP
#  include "AMateria.hpp"
# endif
# ifndef ICHARACTER_HPP
#  include "ICharacter.hpp"
# endif

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure* other);
		Cure& operator=(const Cure& other);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
