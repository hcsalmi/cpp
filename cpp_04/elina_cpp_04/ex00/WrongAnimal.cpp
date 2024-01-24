/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:26:43 by esirnio           #+#    #+#             */
/*   Updated: 2023/11/26 16:27:22 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type = cpy.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cpy) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	type = cpy.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() {
	std::cout << "WrongAnimal makes sound" << std::endl;
}