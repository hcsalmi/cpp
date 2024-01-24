/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:28:07 by esirnio           #+#    #+#             */
/*   Updated: 2023/11/26 16:30:37 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : type("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cpy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	type = cpy.type;
}

WrongCat &WrongCat::operator=(const WrongCat &cpy) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	type = cpy.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() {
	std::cout << "WrongCat meows" << std::endl;
}
