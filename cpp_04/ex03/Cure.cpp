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

Cure::Cure() : _type("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &src)
{
	std::cout << "Cure copy constructor called" << std::endl;
	//copy stuff here
}

Cure	&Cure::operator=(const Cure &src)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &src)
	{
		//copy stuff here
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure* Cure::clone() const
{

}

void use(ICharacter &target)
{

}
