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

Character::Character(): _name("unnamed")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = nullptr;
	}
}

Character::Character(std::string name): _name(name)
{
	std::cout << "Character name constructor called for " << name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = nullptr;
	}
}

Character::Character(const Character &src)
{
	std::cout << "Character copy constructor called" << std::endl;
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = src._inventory[i];
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
			_inventory[i] = src._inventory[i];
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != nullptr)
			delete (this->_inventory[i]);
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)		//can equip many of the same materia?
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
			std::cout << "Equipped " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Cannot equip. No space in inventory" << std::endl;
}

void Character::unequip(int idx)
{
	AMateria *toDiscard;		//luodaan aina uusi joka laitetaan "listaan"
	//trash stuff here
	(void)idx;
}

void Character::use(int idx, ICharacter &target)
{
	if ((idx < 0 || idx > 3) || this->_inventory[idx] == nullptr)
	{
		std::cout << _name << " has no materia to use on " << target.getName() << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}
