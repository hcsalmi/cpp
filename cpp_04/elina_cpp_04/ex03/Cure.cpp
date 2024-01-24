/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:20:50 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/08 13:22:33 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	_type = "cure";
}

Cure::Cure(Cure const &other) {
	_type = other._type;
}

Cure::~Cure() {
}

Cure &Cure::operator=(const Cure &other) {
	_type = other._type;
	return *this;
}

Cure *Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter &target)	{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}