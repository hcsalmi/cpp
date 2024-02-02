/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Discard.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:58:33 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/29 18:58:35 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Discard.hpp"

Discard *Discard::_head;

Discard::Discard() : _materia(nullptr), _next(nullptr)
{
	std::cout << "Discard default constructor called" << std::endl;
	this->_head = this;
}

Discard::Discard(AMateria *toDiscard) : _materia(toDiscard), _next(nullptr)
{
	std::cout << "Discard AMateria parameter constructor called" << std::endl;
	return ;
}

Discard::Discard(const Discard &src)
{
	std::cout << "Discard copy constructor called" << std::endl;
	this->_materia = src._materia;
	this->_next = src._next;
	this->_head = src._head;
}

Discard &Discard::operator=(const Discard &src)
{
	std::cout << "Discard copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_materia = src._materia;
		this->_next = src._next;
		this->_head = src._head;
	}
	return (*this);
}

Discard::~Discard()
{

}

void Discard::add(AMateria *materia)
{
	if (_head == nullptr)
	{
		_head = new Discard(materia);
	}
	else
	{
		Discard *temp;
		temp = _head;
		while (temp->_next != nullptr)
		{
			if (materia == temp->_materia)
				return ;
			temp = temp->_next;
		}
		if (materia == temp->_materia)
			return ;
		temp->_next = new Discard(materia);
	}
}

/*
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
 */



//how to delete discard pile
//do i need to discard stuff from dude's inventory before deleting?