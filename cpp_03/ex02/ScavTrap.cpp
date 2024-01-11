/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:03:34 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/10 20:03:36 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src)
	{
		std::cout << "ScavTrap copy assignment operator called" << std::endl;
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack. He is not longer with us." << std::endl;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy to attack." << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}

void	ScavTrap::guardGate()
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot enter gate keeper mode. He has passed to the other side." << std::endl;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy to enter gate keeper mode." << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " has entered gate keeper mode. Nun shall pass." << std::endl;
	}
}