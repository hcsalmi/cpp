/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:54:51 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/05 16:04:40 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Trash.hpp"

Trash *Trash::_head;

Trash::Trash()
{
	_head = this;
	_next = NULL;
	_data = NULL;
}

Trash::~Trash() {}

Trash::Trash(const Trash &other) { (void)other; }

Trash &Trash::operator=(const Trash &other)
{
	(void)other;
	return (*this);
}

Trash::Trash(AMateria *data)
{
	_data = data;
	_next = NULL;
}

void Trash::add(AMateria *data)
{
	Trash *current;

	for (current = _head; current->_next; current = current->_next)
	{
		if (data == current->_data)
			return ;
	}
	current->_next = new Trash(data);
}

void Trash::emptyTrash()
{
	Trash *tmp;
	Trash *current;

	current = _head->_next;
	while (current)
	{
		tmp = current->_next;
		delete current->_data;
		delete current;
		current = tmp;
	}
	_head->_next = NULL;
}
