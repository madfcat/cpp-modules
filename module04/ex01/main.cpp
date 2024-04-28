/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:35:23 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/28 18:05:35 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void fill_ideas(int n, std::string type, Brain* brain)
{
	(void)type;
	(void)n;
	for (int i = 0; i < 100; i++)
		// brain->setIdea(i, "Hello world!");
		brain->setIdea(i, type + " #" + std::to_string(n) + " Idea #" + std::to_string(i));
}

int main() {
/* 	std::cout << "====== Test from PDF ======" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		delete j;//should not create a leak
		delete i;
	} */
	
/* 	std::cout << std::endl;
	std::cout << "====== More tests ======" << std::endl;
	{
		const int n = 10;
		Animal* animals[n];

		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				animals[i] = new Dog();
		 		fill_ideas(i, animals[i]->getType(), reinterpret_cast<Dog*>(animals[i])->getBrain());
			}
			else
			{
				animals[i] = new Cat();
		 		fill_ideas(i, animals[i]->getType(), reinterpret_cast<Cat*>(animals[i])->getBrain());
			}
		}

		for (int i = 0; i < n; i++)
		{
			animals[i]->makeSound();
		}

		for (int i = 0; i < 100; i++)
		{
			if (i % 2 == 0)
				std::cout << i << ". "<< reinterpret_cast<Dog*>(animals[0])->getBrain()->getIdea(i) << std::endl;
			else
				std::cout << i << ". "<< reinterpret_cast<Cat*>(animals[0])->getBrain()->getIdea(i) << std::endl;
		}

		for (int i = 0; i < n; i++)
			delete animals[i];
	} */

	std::cout << std::endl;
	std::cout << "====== Shallow copy constructor test ======" << std::endl;
	{
		const int n = 2;
		Animal* animals[n];

		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				animals[i] = new Dog();
				fill_ideas(i, animals[i]->getType(), reinterpret_cast<Dog*>(animals[i])->getBrain());
			}
			else
			{
				animals[i] = new Cat();
				fill_ideas(i, animals[i]->getType(), reinterpret_cast<Cat*>(animals[i])->getBrain());
			}
		}
		Animal* copyDog = new Dog(*reinterpret_cast<Dog*>(animals[0]));
		copyDog->makeSound();

		
		std::cout << "== Let's check copyDog and original" << std::endl;
		std::cout << reinterpret_cast<Dog*>(copyDog)->getBrain()->getIdea(0) << std::endl;
		std::cout << reinterpret_cast<Dog*>(animals[0])->getBrain()->getIdea(0) << std::endl;

		std::cout << "== Let's change copyDog and now check copyDog and original" << std::endl;
		reinterpret_cast<Dog*>(copyDog)->getBrain()->setIdea(0, "Hello world!");
		std::cout << reinterpret_cast<Dog*>(copyDog)->getBrain()->getIdea(0) << std::endl;
		std::cout << reinterpret_cast<Dog*>(animals[0])->getBrain()->getIdea(0) << std::endl;
		std::cout << "== Now let's remove animals array" << std::endl;
		for (int i = 0; i < n; i++)
			delete animals[i];
		std::cout << "== And finally remove copyDog" << std::endl;
		delete copyDog;
	}

	return (0);
}