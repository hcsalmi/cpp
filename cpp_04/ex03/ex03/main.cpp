/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:09:17 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/26 20:09:19 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << std::endl;
	{
		std::cout << "=================================================" << std::endl;
		std::cout << "* * * * * Subject test * * * * *" << std::endl;
		std::cout << "=================================================" << std::endl;
		IMateriaSource* src = new MateriaSource();
		std::cout << std::endl;

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;

		ICharacter* me = new Character("me");
		AMateria* tmp;
		std::cout << std::endl;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << std::endl;

		ICharacter* you = new Character("Mailman");
		std::cout << std::endl;

		std::cout << me->getName() << " uses stuff on " << you->getName() << std::endl;
		me->use(0, *you);
		me->use(1, *you);
		std::cout << std::endl;

		delete you;
		delete me;
		delete src;
		std::cout << std::endl;
		std::cout << "=================================================" << std::endl;
	}
	{
		std::cout << "* * * * * Other tests * * * * *" << std::endl;
		std::cout << "=================================================" << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		std::cout << std::endl;

		ICharacter* me = new Character("Mike the Magnificent");
		std::cout << std::endl;

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		std::cout << std::endl;

		tmp = src->createMateria("cure");
		me->equip(tmp);

		std::cout << std::endl;
		ICharacter* you = new Character("Amadeus the Amazing");
		std::cout << std::endl;
		std::cout << me->getName() << " uses stuff on " << you->getName() << std::endl;
		me->use(0, *you);
		me->use(1, *you);
		me->unequip(0);
		me->use(0, *you);
		me->unequip(0);

		std::cout << "------------------------------------------------" << std::endl;
		delete me;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "=================================================" << std::endl;

		tmp = src->createMateria("ice");
		Character *me2 = new Character("Abominable Snowman");
		std::cout << std::endl;

		me2->equip(tmp);
		me2->use(0, *you);
		me2->unequip(0);
		Character *you2 = new Character(*me2);
		std::cout << std::endl;
		delete me2;
		you2->use(0, *you);
		std::cout << "=================================================" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		delete you2;
		delete you;
		delete src;
		std::cout << "------------------------------------------------" << std::endl;
	}
	return (0);
}
