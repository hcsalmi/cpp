/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:10:32 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/04 13:10:33 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::debug(void)
{
	std::cout << "DEBUG: \tI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO: \tI cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR: \tThis is unacceptable! I want to speak to the manager now." << std::endl;
}

/* An array of pointers to (above) member functions of the Harl class */
void	Harl::complain(std::string level)
{
	std::string	complaints[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*f_ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			i = 0;

	while (i < 4)
	{
		if (complaints[i] == level)
		{
			(this->*f_ptr[i])();
		}
		i++;
	}
}