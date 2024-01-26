/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:03:22 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/26 20:03:26 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string	_type; //init as ice
	public:
		Ice();
		Ice(const Ice &src);
		Ice &operator=(const Ice &src);
		~Ice();

		Ice* clone() const;
		void use(ICharacter &target);
};

#endif
