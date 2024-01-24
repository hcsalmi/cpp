/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:17:15 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/07 19:39:13 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	_idx = 0;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

MateriaSource::MateriaSource(MateriaSource &cpy) {
	for (int i = 0; i < 4; i++)
	{
		_materias[i] = cpy._materias[i];
	}
	_idx = cpy._idx;
}

MateriaSource &MateriaSource::operator=(MateriaSource &cpy) {
	for (int i = 0; i < 4; i++)
	{
		_materias[i] = cpy._materias[i];
	}
	_idx = cpy._idx;
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (_idx < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!_materias[i])
			{
				_materias[i] = m;
				_idx++;
				return ;
			}
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	}

	return 0;
}
