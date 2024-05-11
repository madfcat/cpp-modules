/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:40:30 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/12 02:22:58 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# ifndef ANIMAL_HPP
#  include "Animal.hpp"
# endif
# ifndef BRAIN_HPP
#  include "Brain.hpp"
# endif
# include <iostream>

class Cat : public Animal
{
	private:
		Brain* brain;

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual ~Cat() override;

		virtual void	makeSound() const override;
		Brain*			getBrain() const;
};

#endif