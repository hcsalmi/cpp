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

Discard::Discard() : _materia(nullptr), _next(nullptr)	//what to do with head here? _head(this)
{
	std::cout << "Discard default constructor called" << std::endl;
	this->_head = this;
}

Discard::Discard(AMateria *toDiscard) : _materia(toDiscard), _next(nullptr)
{
	//what to do with head here? Think of an implementation without the head?
}


