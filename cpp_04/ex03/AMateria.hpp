/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:08:05 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/26 18:08:07 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>


//katso mitka tulee virtual ja const

class AMateria
{
	protected:
		//insert stuff here, type?

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &src);
		AMateria &operator=(const AMateria &src);
		~AMateria();

		std::string const &getType() const;	//Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
