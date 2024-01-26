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

Character::Character(): _name("")	//joku init tahan?
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name)
{
	std::cout << "Character name constructor called" << std::endl;
	this->_name = name;
	//inventory
}

Character::Character(const Character &src)
{
	std::cout << "Character copy constructor called" << std::endl;
	this->_name = src._name;
	//inventory
}

Character &Character::operator=(const Character &src)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		//inventory
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	//where freeing?
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter &target)
{

}
