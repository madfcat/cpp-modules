/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:35:23 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/27 19:39:58 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete (meta);
		delete (j);
		delete (i);
	}

	std::cout << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		meta->makeSound();

		delete (meta);
		delete (i);
	}

	std::cout << std::endl;
	{	
		std::cout << " " << std::endl;
		std::cout << "====== Testing copy constructor ======" << std::endl;
		const Cat* firstCat = new Cat();
		const Cat* secondCat = new Cat(*firstCat);

		delete (firstCat);
		delete (secondCat);

		std::cout << std::endl;
		std::cout << "====== Testing assignment operator ======" << std::endl;
		Cat someCat;
		Cat& referenceCat = someCat;
		std::cout << "== Creating dynamically allocated thirdCat:" << std::endl;
		Cat* thirdCat = new Cat();
		std::cout << "== Assignment operator:" << std::endl;
		referenceCat = *thirdCat;

		delete (thirdCat);
	}

	return (0);
}