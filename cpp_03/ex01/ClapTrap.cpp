/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:12:08 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/10 17:12:10 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return (*this);
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack. He is not longer with us." << std::endl;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to attack." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't take damage. He's already gone." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage." << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints <= 0)
		{
			this->_hitPoints = 0;
			std::cout << "Sadly, ClapTrap " << this->_name << " has died." << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot repair. He's already passed on." << std::endl;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot repair. He has run out of juice." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself by " << amount << " points." << std::endl;
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
	}
}
