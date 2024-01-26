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

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria type constructor called" << std::endl;	//is it?
	//init type?
}

AMateria::AMateria(const AMateria &src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	//copy stuff here
}

AMateria &AMateria::operator=(const AMateria &src)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &src)
	{
		//copy stuff here
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

/* returns the materia type */
std::string const &AMateria::getType() const
{

}

void AMateria::use(ICharacter &target)
{

}
