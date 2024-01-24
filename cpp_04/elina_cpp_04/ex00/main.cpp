/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:17:32 by esirnio           #+#    #+#             */
/*   Updated: 2023/11/26 16:36:50 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animal_ptr = new Animal();
	Animal animal = Animal(*animal_ptr);
	Cat *cat_ptr = new Cat();
	Cat cat = Cat(*cat_ptr);
	Dog *dog_ptr = new Dog();
	Dog dog = Dog(*dog_ptr);
	WrongAnimal *wrong_animal_ptr = new WrongAnimal();
	WrongAnimal wrong_animal = WrongAnimal(*wrong_animal_ptr);
	WrongCat *wrong_cat_ptr = new WrongCat();
	WrongCat wrong_cat = WrongCat(*wrong_cat_ptr);

	std::cout << std::endl;
	animal_ptr->makeSound();
	animal.makeSound();
	std::cout << std::endl;
	cat_ptr->makeSound();
	cat.makeSound();
	cat.Animal::makeSound();
	std::cout << std::endl;
	dog_ptr->makeSound();
	dog.makeSound();
	dog.Animal::makeSound();
	std::cout << std::endl;
	wrong_animal_ptr->makeSound();
	wrong_animal.makeSound();
	std::cout << std::endl;
	wrong_cat_ptr->makeSound();
	wrong_cat.makeSound();
	wrong_cat.WrongAnimal::makeSound();
	std::cout << std::endl;
	delete animal_ptr;
	delete cat_ptr;
	delete dog_ptr;
	delete wrong_animal_ptr;
	delete wrong_cat_ptr;
	return (0);
}
