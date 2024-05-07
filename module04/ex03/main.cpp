/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:40 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/07 19:34:31 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// void freeSource(IMateriaSource* src)
// {
// 	for (int i = 0; i < 4; i++)
// 		delete (dynamic_cast<MateriaSource*>(src)->getStorage()[i]);
// }

int main() {
	std::cout << "====== Test from PDF ======" << std::endl;
	{
		IMateriaSource* src = new MateriaSource(); 
		src->learnMateria(new Ice()); 
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		delete tmp; // Fixing memory leak
		std::cout << tmp << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		delete tmp; // Fixing memory leak
		std::cout << tmp << std::endl;

		ICharacter* bob = new Character("bob"); 

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob; 
		delete me;
		delete src;
	}

	std::cout << std::endl;

	// std::cout << "====== More Tests ======" << std::endl;
	// {
	// 	ICharacter* jane = new Character("Jane");
	// 	ICharacter* mary = new Character("Mary");
		
	// 	std::cout << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(new Ice());
		
	// 	std::cout << std::endl;
	// 	jane->equip(new Ice());
	// 	jane->use(0, *mary);

	// 	std::cout << std::endl;
	// 	jane->equip(src->createMateria("ice"));
	// 	mary->equip(src->createMateria("cure"));

	// 	std::cout << std::endl;

	// 	delete (jane);
	// 	delete (mary);
	// }
	
	
	return 0; 
}