/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Trash.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:52:52 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/07 17:27:46 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASH_HPP
#define TRASH_HPP

#include "AMateria.hpp"

class AMateria;

class Trash
{
	public:
		Trash();
		~Trash();
		Trash(const Trash &other);
		Trash &operator=(const Trash &other);
		Trash(AMateria *data);
		void add(AMateria *data);
		void emptyTrash();
	private:
		AMateria *_data;
		Trash *_next;
		static Trash *_head;
};

#endif