/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:17:32 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/08 13:49:44 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[4];
	Dog *dog_ptr = NULL;
	Dog *dog_cpy = new Dog();

	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if (i & 1)
		{
			animals[i] = new Cat();
		}
		else
		{
			animals[i] = new Dog();
		}
	}
	dog_ptr = (Dog *)animals[0];
	dog_ptr->setIdea("* * * So interesting idea * * *");
	*dog_cpy = *dog_ptr;
	for (i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
	dog_cpy->printIdeas();
	delete dog_cpy;

	return (0);
}
