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
		const Animal	*animal = new Animal();
		const Animal	*dog = new Dog();
		const Animal	*cat = new Cat();

		std::cout << "Animal type: " << dog->getType() << " " << std::endl;
		std::cout << "Animal type: " << cat->getType() << " " << std::endl;
		std::cout << "Animal type: " << animal->getType() << " " << std::endl;
		dog->makeSound();
		cat->makeSound();
		animal->makeSound();
		delete dog;
		delete cat;
		delete animal;
		std::cout << std::endl;
	}
	{
		const WrongAnimal	*wAnimal = new WrongAnimal();
		const WrongAnimal	*wCat = new WrongCat();

		std::cout << "Animal type: " << wCat->getType() << " " << std::endl;
		std::cout << "Animal type: " << wAnimal->getType() << " " << std::endl;
		wCat->makeSound();
		wAnimal->makeSound();
		delete wCat;
		delete wAnimal;
		std::cout << std::endl;
	}
	return (0);
}
