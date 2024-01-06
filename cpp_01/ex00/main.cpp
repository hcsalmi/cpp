/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:49:45 by lsalmi            #+#    #+#             */
/*   Updated: 2023/12/18 14:49:47 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	stackChump("stackChump");
	Zombie	*heapZombie;

	heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	stackChump.announce();
	randomChump("anotherChump");
	delete heapZombie;
	return (0);
}
