/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:40 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/08 19:30:01 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
/* 	{
		std::cout << "====== Test from PDF ======" << std::endl;
		IMateriaSource* src = new MateriaSource(); 
		src->learnMateria(new Ice()); 
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		std::cout << tmp << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << tmp << std::endl;

		ICharacter* bob = new Character("bob"); 

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob; 
		delete me;
		delete src;
	} */

	/* {
		std::cout << std::endl;
		std::cout << "====== More Tests ======" << std::endl;
		std::cout << "=== Create characters" << std::endl;
		ICharacter* jane = new Character("Jane");
		ICharacter* mary = new Character("Mary");
		
		std::cout << std::endl;
		std::cout << "=== Create Materia Source / Learn materia" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());

		std::cout << std::endl;
		std::cout << "=== Equip / Use" << std::endl;
		jane->equip(new Ice());
		jane->use(0, *mary);

		std::cout << std::endl;
		jane->equip(src->createMateria("cure"));
		mary->equip(src->createMateria("cure"));

		std::cout << std::endl;
		std::cout << "=== Unequip" << std::endl;
		AMateria* floor[500] = {nullptr};
		floor[0] = dynamic_cast<Character*>(jane)->getInventory(0);
		floor[1] = dynamic_cast<Character*>(jane)->getInventory(1);
		floor[2] = dynamic_cast<Character*>(mary)->getInventory(0);

		jane->unequip(0);
		jane->unequip(1);
		mary->unequip(0);

		delete (floor[0]);
		delete (floor[1]);
		delete (floor[2]);

		std::cout << std::endl;
		std::cout << "=== Destroy Jane, Mary and MateriaSource" << std::endl;
		delete (jane);
		delete (mary);
		delete (src);
	} */

	{
		std::cout << std::endl;
		std::cout << "====== Copy constructors test ======" << std::endl;
		
		std::cout << "== Characters copy constructors test ==" << std::endl;
		ICharacter* julia = new Character("Julia");
		ICharacter* juliaCopy = new Character(*dynamic_cast<Character*>(julia));

		std::cout << julia->getName() << std::endl;
		std::cout << juliaCopy->getName() << std::endl;

		std::cout << "== Materias copy constructors test ==" << std::endl;
		std::cout << "= Ice" << std::endl;
		AMateria* ice = new Ice();
		AMateria* copiedIce = new Ice(*dynamic_cast<Ice*>(ice));
		copiedIce->use(*julia);
		
		std::cout << "= Cure" << std::endl;
		AMateria* cure = new Cure();
		AMateria* copiedCure = new Cure(*dynamic_cast<Cure*>(cure));
		copiedCure->use(*julia);

		std::cout << "== Materia copy constructors test ==" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());

		// IMateriaSource* copiedSrc = new MateriaSource(*dynamic_cast<MateriaSource*>(src));
		
		
		std::cout << "== Delete Materias" << std::endl;
		delete (ice);
		delete (copiedIce);
		delete (cure);
		delete (copiedCure);
		std::cout << "== Delete Characters" << std::endl;
		delete (julia);
		delete (juliaCopy);
		std::cout << "== Delete MateriaSource" << std::endl;
		delete (src);
	}
	
/* 	{
		std::cout << std::endl;
		std::cout << "====== Assignment operators test ======" << std::endl;
		
		std::cout << "== Characters assignment operators test ==" << std::endl;
		ICharacter* julia = new Character("Julia");
		ICharacter* john = new Character("John");
		ICharacter& juliaCopy = dynamic_cast<Character&>(*julia);
		juliaCopy = *john;

		std::cout << "== Materias assignment operators test ==" << std::endl;
		std::cout << "= Ice" << std::endl;
		AMateria* ice = new Ice();
		AMateria* anotherIce = new Ice();
		AMateria& referenceIce = dynamic_cast<Ice&>(*ice);
		referenceIce = *anotherIce;
		referenceIce.use(*julia);

		std::cout << "= Cure" << std::endl;
		AMateria* cure = new Cure();
		AMateria* anotherCure = new Cure();
		AMateria& referenceCure = dynamic_cast<Cure&>(*cure);
		referenceCure = *anotherCure;
		referenceCure.use(*julia);
		
		std::cout << "== Delete Materias" << std::endl;
		delete (ice);
		delete (anotherIce);
		delete (cure);
		delete (anotherCure);
		std::cout << "== Delete Characters" << std::endl;
		delete (julia);
		delete (john);
	} */
	return (0);
}