/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:03:40 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/10 20:03:42 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string);
		ScavTrap(ScavTrap const &src);
		~ScavTrap();

		ScavTrap &operator=(ScavTrap const &scr);

		void	attack(const std::string &target);
		void	guardGate();
};

#endif
