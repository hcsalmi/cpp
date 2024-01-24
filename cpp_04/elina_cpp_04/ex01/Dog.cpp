/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:51:17 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/07 16:31:38 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : type("Dog"), brain(new Brain) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) {
	std::cout << "Dog copy constructor called" << std::endl;
	type = cpy.type;
	brain = new Brain(*cpy.brain);
}

Dog &Dog::operator=(const Dog &cpy) {
	std::cout << "Dog assignment operator called" << std::endl;
	type = cpy.type;
	*brain = *(cpy.brain);
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() {
	std::cout << "Dog barks" << std::endl;
}

void Dog::setIdea(std::string idea)
{
	brain->setIdea(idea);
}

void Dog::printIdeas()
{
	brain->printIdeas();
}