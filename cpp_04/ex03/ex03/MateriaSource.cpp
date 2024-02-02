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
	for (int i = 0; i < 4; i++)
	{
		_materias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_materias[i] = src._materias[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			_materias[i] = src._materias[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != nullptr)
			delete (this->_materias[i]);
	}
}

void MateriaSource::learnMateria(AMateria *newMateria)
{
	int	i = 0;

	while (i < 4)
	{
		if (this->_materias[i] != nullptr)
			i++;
		else
		{
			this->_materias[i] = newMateria;
			std::cout << "AMateria of type " << this->_materias[i]->getType() << " learned" << std::endl;
			return ;
		}
	}
	std::cout << "\e[0;31mCannot learn more materia\e[0m" << std::endl;
	delete newMateria;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int	i = 0;

	if (type == "unknown materia")
		return (0);
	while (i < 4)
	{
		if (this->_materias[i]->getType() != type)
			i++;
		else
		{
			return (this->_materias[i]->clone());
		}
	}
	std::cout << "\e[0;31mFailed to create materia\e[0m" << std::endl;
	return (0);
}
