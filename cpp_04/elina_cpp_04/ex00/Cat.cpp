/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:49:45 by esirnio           #+#    #+#             */
/*   Updated: 2023/11/26 16:20:20 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : type("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) {
	std::cout << "Cat copy constructor called" << std::endl;
	type = cpy.type;
}

Cat &Cat::operator=(const Cat &cpy) {
	std::cout << "Cat assignment operator called" << std::endl;
	type = cpy.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() {
	std::cout << "Cat meows" << std::endl;
}
