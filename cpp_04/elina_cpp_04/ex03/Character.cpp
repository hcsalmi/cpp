/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:54:30 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/07 19:33:04 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	_name = "no name";
	_inv_idx = 0;
}

Character::Character(const std::string name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	_inv_idx = 0;
	_name = name;
}

Character::Character(const Character &cpy) {
	for (int i = 0; i < _inv_idx; i++)
		_inventory[i] =  (cpy._inventory[i])->clone();
	_inv_idx = cpy._inv_idx;
	_name = cpy._name;
}

Character &Character::operator=(const Character &cpy) {
	_name = cpy._name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = (cpy._inventory[i])->clone();
	_inv_idx = cpy._inv_idx;
	return *this;
}

Character::~Character() {
	for (int i = 0; i < _inv_idx; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (_inv_idx == 4 || !m)
		return;
	for(int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
			return ;
	}
	_inventory[_inv_idx] = m;
	_inv_idx++;
}

void Character::unequip(int idx) {
	AMateria *materia;

	if (idx < 0 || idx > 3 || _inv_idx == 0)
		return;
	materia = _inventory[idx];
	for (int i = idx; i < _inv_idx - 1; i++)
	{
		_inventory[i] = _inventory[i + 1];
	}
	_trash.add(materia);
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || _inv_idx == 0 || idx > _inv_idx)
		return;
	if (_inventory[idx])
	{
		_inventory[idx]->use(target);
	}
}

void Character::deleteMaterias()
{
	while (_inv_idx > 0)
	{
		unequip(_inv_idx);
		_inv_idx--;
	}
	_trash.emptyTrash();
}