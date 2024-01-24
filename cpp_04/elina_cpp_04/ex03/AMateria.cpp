/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:46:05 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/07 19:35:32 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("") {
}

AMateria::AMateria(std::string type) : _type(type) { 
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &cpy) {
	std::cout << "AMateria copy constructor called" << std::endl;
	_type = cpy._type;
}

AMateria &AMateria::operator=(const AMateria &cpy) {
	std::cout << "AMateria assignment operator called" << std::endl;
	_type = cpy._type;
	return *this;
}

AMateria::~AMateria() {
}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "use " << _type << " on " << target.getName() << std::endl;
}