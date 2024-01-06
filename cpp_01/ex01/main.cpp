/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:19:39 by lsalmi            #+#    #+#             */
/*   Updated: 2023/12/18 19:19:41 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	Zombie	testSubject("testSubject");
	Zombie	anotherVictim("anotherVictim");
	int n = 8;

	horde = zombieHorde(n, "Sam");
	testSubject.announce();
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	anotherVictim.announce();
	delete[] horde;
	return (0);
}
