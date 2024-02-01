/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Discard.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:58:26 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/29 18:58:28 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISCARD_HPP
#define DISCARD_HPP

#include "AMateria.hpp"

class Discard
{
	private:
		AMateria		*_materia;
		Discard			*_next;
		static Discard	*_head;
	public:
		Discard();
		Discard(AMateria *toDiscard);
		Discard(const Discard &src);
		Discard	&operator=(const Discard &src);
		~Discard();
		void	add(AMateria *toDiscard);
//empty trash?

};

#endif
