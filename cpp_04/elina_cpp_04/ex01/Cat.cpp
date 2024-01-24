/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:49:45 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/07 19:20:20 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : type("Cat"), brain(new Brain) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) {
	std::cout << "Cat copy constructor called" << std::endl;
	type = cpy.type;
	brain = new Brain(*cpy.brain);
}

Cat &Cat::operator=(const Cat &cpy) {
	std::cout << "Cat assignment operator called" << std::endl;
	type = cpy.type;
	*brain = *(cpy.brain);
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() {
	std::cout << "Cat meows" << std::endl;
}
