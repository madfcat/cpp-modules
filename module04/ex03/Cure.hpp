/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:23 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/01 14:22:51 by vshchuki         ###   ########.fr       */
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
	private:
		std::string name;

	public:
		Cure();
		Cure(const Cure* other);
		Cure& operator=(const Cure& other);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);

		const std::string& getName() const;
};

#endif
