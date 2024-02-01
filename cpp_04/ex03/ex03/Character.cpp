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
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			_inventory[i] = src._inventory[i]->clone();
		}
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
	//delete trash stuff
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (m == nullptr)
	{
		std::cout << "Cannot equip nonexistent materia." << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == nullptr)
		{
			this->_inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "Cannot equip. No space in inventory" << std::endl;
}

void Character::unequip(int idx)
{
	AMateria *toDiscard;


//	std::cout << _inventory[idx]->getType() << " in slot " << idx << std::endl;
	if ((idx < 0 || idx > 3) || this->_inventory[idx] == nullptr)
		return ;
	std::cout << this->_name << " unequips " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
	toDiscard = _inventory[idx];
	_inventory[idx] = nullptr;					///memory management?
	_trash->add(toDiscard);
}

void Character::use(int idx, ICharacter &target)
{
	if ((idx < 0 || idx > 3) || this->_inventory[idx] == nullptr)
	{
		std::cout << _name << " has no materia to use on " << target.getName() << " in slot " << idx << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}
