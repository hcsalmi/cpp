/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:11:42 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/10 17:11:43 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clapOne("Ben");
	ClapTrap	clapTwo("Jerry");
	ClapTrap	testClap;
	ClapTrap	copyClap(clapOne);

	int i = 0;
	testClap = clapTwo;

	std::cout << std:: endl;
	clapOne.attack("Jerry");
	clapTwo.takeDamage(9);
	clapTwo.beRepaired(1);
	std::cout << std:: endl;
	std::cout << "ClapTrap " << clapTwo.getName() << " goes on a rampage!" << std::endl;
	while (i++ < 6)
	{
		clapTwo.attack("Ben");
		clapOne.takeDamage(1);
	}
	clapOne.beRepaired(1);
	std::cout << "ClapTrap " << clapOne.getName() << " hitpoints: " << clapOne.getHitPoints() << ", energy points " << clapOne.getEnergyPoints() << std:: endl;
	std::cout << "ClapTrap " << clapTwo.getName() << " hitpoints: " << clapTwo.getHitPoints() << ", energy points " << clapTwo.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;
	clapOne.attack("Jerry");
	clapTwo.takeDamage(3);
	clapTwo.beRepaired(1);
	clapTwo.attack("Ben");
	std::cout << "ClapTrap " << clapOne.getName() << " hitpoints: " << clapOne.getHitPoints() << ", energy points " << clapOne.getEnergyPoints() << std:: endl;
	std::cout << "ClapTrap " << clapTwo.getName() << " hitpoints: " << clapTwo.getHitPoints() << ", energy points " << clapTwo.getEnergyPoints() << std:: endl;
	std::cout << std:: endl;
	std::cout << "ClapTrap " << clapOne.getName() << " goes on a rampage!" << std::endl;
	i = 0;
	while (i++ < 8)
	{
		clapOne.attack("Supermarket cashier");
	}
	clapOne.beRepaired(1);
	std::cout << std:: endl;

	return (0);
}