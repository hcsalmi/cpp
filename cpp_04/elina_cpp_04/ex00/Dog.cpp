/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:51:17 by esirnio           #+#    #+#             */
/*   Updated: 2023/11/26 16:21:17 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : type("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) {
	std::cout << "Dog copy constructor called" << std::endl;
	type = cpy.type;
}

Dog &Dog::operator=(const Dog &cpy) {
	std::cout << "Dog assignment operator called" << std::endl;
	type = cpy.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() {
	std::cout << "Dog barks" << std::endl;
}
