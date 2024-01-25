/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:07:10 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/22 17:07:12 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl;
	{
		std::cout << "* * * * * Subject test * * * * *" << std::endl;

		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		delete dog;
		delete cat;
		std::cout << std::endl;
	}

	{
		std::cout << "* * * * * More tests * * * * *" << std::endl;

		//Animal *not_compile = new Animal;
		int	size = 8;
		int	half = size / 2;
		Animal *animals[size];

		for (int i = 0; i < size; i++)
		{
			if (i < half)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		std::cout << std::endl;
		std::cout << "* Animal array created for array size " << size << " *\t" << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << "Animal type: " << animals[i]->getType() << std::endl;
			animals[i]->makeSound();
		}
		std::cout << std::endl;

		for (int i = 0; i < size; i++)
		{
			delete animals[i];
		}
		std::cout << std::endl;
	}

	{
		std::cout << "* * * * * Shallow copy test * * * * *" << std::endl;

		Cat *cat = new Cat();
		Dog *dog = new Dog();
		Cat *cat2 = new Cat(*cat);
		Dog *dog2 = new Dog(*dog);

		std::cout << std::endl;
		std::cout << "Cat idea: ";
		cat->getIdea(0) ;
		std::cout << "Cat2 idea: ";
		cat2->getIdea(0);
		std::cout << "Dog idea: ";
		dog->getIdea(0);
		std::cout << "Dog2 idea: ";
		dog2->getIdea(0);
		std::cout << std::endl;
		cat->setIdea(0, "I am a cat");
		dog->setIdea(0, "I am a dog");
		std::cout << "* Changing ideas *\t" << std::endl << std::endl;
		std::cout << "Cat idea: ";
		cat->getIdea(0);
		std::cout << "Cat2 idea: ";
		cat2->getIdea(0);
		std::cout << "Dog idea: ";
		dog->getIdea(0);
		std::cout << "Dog2 idea: ";
		dog2->getIdea(0);
		std::cout << std::endl;
		delete cat;
		delete dog;
		delete cat2;
		delete dog2;
	}

	return 0;
}
