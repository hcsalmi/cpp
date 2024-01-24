/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:35:03 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/07 19:26:35 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"

Ice::Ice() {
	_type = "ice";
}

Ice::~Ice(){
}

Ice::Ice(const Ice &cpy){
	_type = cpy._type;
}

Ice &Ice::operator=(const Ice &cpy) {
	_type = cpy._type;
	return (*this);
}

Ice *Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << "* Shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
