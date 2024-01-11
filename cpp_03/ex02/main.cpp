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
#include "FragTrap.hpp"

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

	testScav = scavTwo;

	FragTrap	fragOne("Sleepy");
	FragTrap	fragTwo("Cranky");
	FragTrap	testFrag;
	FragTrap	copyFrag(fragOne);


	std::cout << std:: endl;
	std::cout << "testFrag name before copy assignment is: " << testFrag.getName() << std::endl;
	testFrag = fragTwo;
	std::cout << std:: endl;
	std::cout << "fragOne name is: " << fragOne.getName() << std::endl;
	std::cout << "fragTwo name is: " << fragTwo.getName() << std::endl;
	std::cout << "testFrag name is: " << testFrag.getName() << std::endl;
	std::cout << "copyFrag name is: " << copyFrag.getName() << std::endl;

	std::cout << std:: endl;
	std::cout << "* * * * * * * * * * * * * * * * * * CLAP * * * * * * * * * * * * * * * * * * * * " << std:: endl;
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
	std::cout << "* * * * * * * * * * * * * * * * * * * SCAV * * * * * * * * * * * * * * * * * * * * " << std:: endl;
	std::cout << std:: endl;
	scavOne.attack(scavTwo.getName());
	scavTwo.takeDamage(scavTwo.getAttackDamage());
	std::cout << "ScavTrap " << scavTwo.getName() << " hitpoints: " << scavTwo.getHitPoints() << ", energy points " << scavTwo.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;

	scavTwo.beRepaired(1);
	std::cout << "ScavTrap " << scavTwo.getName() << " hitpoints: " << scavTwo.getHitPoints() << ", energy points " << scavTwo.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;
	std::cout << "ScavTrap " << scavTwo.getName() << " goes on a rampage!" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		scavTwo.attack(scavOne.getName());
		scavOne.takeDamage(scavTwo.getAttackDamage());
	}
	scavOne.beRepaired(1);
	scavOne.attack("Redbeard");
	scavOne.guardGate();
	std::cout << "ScavTrap " << scavOne.getName() << " hitpoints: " << scavOne.getHitPoints() << ", energy points " << scavOne.getEnergyPoints() << std:: endl;
	std::cout << "ScavTrap " << scavTwo.getName() << " hitpoints: " << scavTwo.getHitPoints() << ", energy points " << scavTwo.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;

	std::cout << std:: endl;
	std::cout << "* * * * * * * * * * * * * * * * * * * * FRAG * * * * * * * * * * * * * * * * * * * " << std:: endl;
	std::cout << std:: endl;

	fragOne.attack(fragTwo.getName());
	fragTwo.takeDamage(fragTwo.getAttackDamage());
	std::cout << "FragTrap " << fragTwo.getName() << " hitpoints: " << fragTwo.getHitPoints() << ", energy points " << fragTwo.getEnergyPoints() << std:: endl;
	std::cout << "FragTrap " << fragOne.getName() << " hitpoints: " << fragOne.getHitPoints() << ", energy points " << fragOne.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;

	std::cout << "FragTrap " << fragTwo.getName() << " goes on a rampage!" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		fragTwo.attack(fragOne.getName());
		fragOne.takeDamage(fragTwo.getAttackDamage());
	}
	fragOne.beRepaired(1);
	fragOne.attack("Redbeard");
	fragOne.highFivesGuys();
	std::cout << "FragTrap " << fragOne.getName() << " hitpoints: " << fragOne.getHitPoints() << ", energy points " << fragOne.getEnergyPoints() << std:: endl;
	std::cout << "FragTrap " << fragTwo.getName() << " hitpoints: " << fragTwo.getHitPoints() << ", energy points " << fragTwo.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;
	fragTwo.highFivesGuys();
	std::cout << std:: endl;
	return (0);
}

