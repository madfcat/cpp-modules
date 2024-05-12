/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:51:53 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/12 20:16:56 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# ifndef AMATERIA_HPP
#  include "AMateria.hpp"
# endif
# ifndef IMATERIASOURCE_HPP
#  include "IMateriaSource.hpp"
# endif
# include <iostream>
# include <string>

class MateriaSource : public IMateriaSource
{
	private:
		static const int storageSize = 4;
		AMateria* storage[storageSize] = {nullptr};

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);

		virtual ~MateriaSource() override;
		virtual void		learnMateria(AMateria*) override;
		virtual AMateria*	createMateria(std::string const & type) override;
};

#endif