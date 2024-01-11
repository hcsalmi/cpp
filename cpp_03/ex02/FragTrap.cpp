/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:48:25 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/11 20:48:27 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
	{
		std::cout << "FragTrap copy assignment operator called" << std::endl;
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot attack. He is not longer with us." << std::endl;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " has no energy to attack." << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot hi five. He is hi fiving with angels now." << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_name << ": You're awesome! Gimme hi fives!" << std::endl;
}
