/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:14:01 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/26 20:14:03 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	//copy stuff here
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &src)
	{
		//copy stuff here
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
}

void learnMateria(AMateria*)
{

}

AMateria *createMateria(std::string const &type)
{

}
