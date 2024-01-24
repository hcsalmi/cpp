/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:29:22 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/08 13:14:01 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "Trash.hpp"

class ICharacter;
class AMateria;

class Character : public ICharacter {
	private:
		AMateria*	_inventory[4];
		std::string _name;
		int			_inv_idx;
		Trash		_trash;
	public:
		Character();
		Character(const std::string name);
		Character(const Character &cpy);
		Character &operator=(const Character &cpy);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void deleteMaterias();
};

#endif