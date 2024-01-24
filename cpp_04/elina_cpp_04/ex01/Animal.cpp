/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:07:59 by esirnio           #+#    #+#             */
/*   Updated: 2023/11/26 16:18:48 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &cpy) {
	std::cout << "Animal copy constructor called" << std::endl;
	type = cpy.type;
}

Animal &Animal::operator=(const Animal &cpy) {
	std::cout << "Animal assignment operator called" << std::endl;
	type = cpy.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() {
	std::cout << "Animal makes sound" << std::endl;
}
