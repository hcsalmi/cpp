/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:07:56 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/26 20:07:58 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &src)
{
	std::cout << "Cure copy constructor called" << std::endl;
	this->_type = src._type;
}

Cure	&Cure::operator=(const Cure &src)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure* Cure::clone() const
{
	return (new Cure());
}

void use(ICharacter &target)
{
	std::cout << "* Heals " << target.getName() << "'s wounds * " << std:: endl;
}
