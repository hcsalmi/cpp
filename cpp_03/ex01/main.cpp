/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:04:32 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/10 20:04:33 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clapOne("Ben");
	ClapTrap	clapTwo("Jerry");
	ClapTrap	testClap;
	ClapTrap	copyClap(clapOne);

	testClap = clapTwo;

	ScavTrap	scavOne("Blackbeard");
	ScavTrap	scavTwo("Redbeard");
	ScavTrap	testScav;
	ScavTrap	copyScav(scavOne);

	std::cout << std:: endl;
	std::cout << "testScav name before copy assignment is: " << testScav.getName() << std::endl;
	testScav = scavTwo;
	std::cout << std:: endl;
	std::cout << "scavOne name is: " << scavOne.getName() << std::endl;
	std::cout << "scavTwo name is: " << scavTwo.getName() << std::endl;
	std::cout << "testScav name is: " << testScav.getName() << std::endl;
	std::cout << "copyScav name is: " << copyScav.getName() << std::endl;

	std::cout << std:: endl;
	std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << std:: endl;
	std::cout << std:: endl;

	clapOne.attack("Jerry");
	clapTwo.takeDamage(9);
	clapTwo.beRepaired(1);
	std::cout << std:: endl;
	std::cout << "ClapTrap " << clapTwo.getName() << " goes on a rampage!" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		clapTwo.attack("Ben");
		clapOne.takeDamage(2);
	}
	clapOne.beRepaired(1);
	scavOne.guardGate();
	std::cout << "ClapTrap " << clapOne.getName() << " hitpoints: " << clapOne.getHitPoints() << ", energy points " << clapOne.getEnergyPoints() << std:: endl;
	std::cout << "ClapTrap " << clapTwo.getName() << " hitpoints: " << clapTwo.getHitPoints() << ", energy points " << clapTwo.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;
	clapOne.attack("Jerry");
	clapTwo.takeDamage(3);
	clapTwo.takeDamage(2);
	clapTwo.beRepaired(1);
	clapTwo.attack("Ben");
	std::cout << "ClapTrap " << clapOne.getName() << " hitpoints: " << clapOne.getHitPoints() << ", energy points " << clapOne.getEnergyPoints() << std:: endl;
	std::cout << "ClapTrap " << clapTwo.getName() << " hitpoints: " << clapTwo.getHitPoints() << ", energy points " << clapTwo.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;
	std::cout << "ClapTrap " << clapOne.getName() << " goes on a rampage!" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		clapOne.attack("Supermarket cashier");
	}
	clapOne.beRepaired(1);

	std::cout << std:: endl;
	std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << std:: endl;
	std::cout << std:: endl;
	scavOne.attack("Redbeard");
	scavTwo.takeDamage(scavTwo.getAttackDamage());
	std::cout << "ScavTrap " << scavTwo.getName() << " hitpoints: " << scavTwo.getHitPoints() << ", energy points " << scavTwo.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;

	scavTwo.beRepaired(1);
	std::cout << "ScavTrap " << scavTwo.getName() << " hitpoints: " << scavTwo.getHitPoints() << ", energy points " << scavTwo.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;
	std::cout << "ScavTrap " << scavTwo.getName() << " goes on a rampage!" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		scavTwo.attack("Blackbeard");
		scavOne.takeDamage(scavTwo.getAttackDamage());
	}
	scavOne.beRepaired(1);
	scavOne.attack("Redbeard");
	scavOne.guardGate();
	std::cout << "ScavTrap " << scavOne.getName() << " hitpoints: " << scavOne.getHitPoints() << ", energy points " << scavOne.getEnergyPoints() << std:: endl;
	std::cout << "ScavTrap " << scavTwo.getName() << " hitpoints: " << scavTwo.getHitPoints() << ", energy points " << scavTwo.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;

	return (0);
}
