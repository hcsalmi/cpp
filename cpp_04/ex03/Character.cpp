/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:11:37 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/26 20:11:39 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("unnamed"), _trash(nullptr)
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = nullptr;
	}
}

Character::Character(std::string name): _name(name), _trash(nullptr)
{
	std::cout << "Character name constructor called for " << name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = nullptr;
	}
}

Character::Character(const Character &src) : _trash(nullptr)
{
	std::cout << "Character copy constructor called" << std::endl;
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i] != nullptr)
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character &Character::operator=(const Character &src)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		_inventory[i] = nullptr;
		if (src._inventory[i] != nullptr)
			_inventory[i] = src._inventory[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called for " << this->_name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != nullptr)
		{
			delete (this->_inventory[i]);
			_inventory[i] = nullptr;
		}
	}
	delete _trash;

}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (m == nullptr)
	{
		std::cout << "\e[0;31mCannot equip nonexistent materia.\e[0m" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == nullptr)
		{
			this->_inventory[i] = m;
			std::cout << this->_name << " equipped " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "\e[0;31mCannot equip. No space in inventory\e[0m" << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
//	AMateria *toDiscard;

	if ((idx < 0 || idx > 3) || this->_inventory[idx] == nullptr)
		return ;
	std::cout << this->_name << " unequips " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
//	toDiscard = _inventory[idx];
	_trash->add(_inventory[idx]);
	_inventory[idx] = nullptr;

}

void Character::use(int idx, ICharacter &target)
{
	if ((idx < 0 || idx > 3) || this->_inventory[idx] == nullptr)
	{
		std::cout << _name << " \e[0;31mhas no materia to use on \e[0m" << target.getName() << " in slot " << idx << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}
