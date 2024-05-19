/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:23 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/19 17:54:22 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		virtual ~Cure() override;

		virtual AMateria*	clone() const override;
		virtual void		use(ICharacter& target) override;
};

#endif
