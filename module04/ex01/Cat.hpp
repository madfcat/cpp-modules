/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:40:30 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/19 17:57:33 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"
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