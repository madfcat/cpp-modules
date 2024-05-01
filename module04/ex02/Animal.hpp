/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:36:35 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/30 01:29:23 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	protected:
		std::string type;
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);

	public:
		virtual ~Animal();
		std::string getType() const;
		virtual void 		makeSound() const;
};

#endif