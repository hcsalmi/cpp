/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:47:15 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/08 13:12:02 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &cpy);
		Cure &operator=(Cure const &cpy);
		~Cure();

		void use(ICharacter &target);
		Cure *clone() const;
};

#endif
