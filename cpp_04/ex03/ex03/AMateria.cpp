/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:08:12 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/26 18:08:14 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("unknown materia")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria of type " << type << " was constructed" << std::endl;
	this->_type = type;
}

AMateria::AMateria(const AMateria &src)
{
	std::cout << "AMateria copy constructor called on " << src._type << std::endl;
	this->_type = src._type;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Uses " << _type << "on " << target.getName() << std:: endl;
}
