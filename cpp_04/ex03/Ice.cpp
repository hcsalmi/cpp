/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:05:52 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/26 20:05:54 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : _type("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &src)
{
	std::cout << "Ice copy constructor called" << std::endl;
	//copy stuff here
}

Ice &Ice::operator=(const Ice &src)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &src)
	{
		//copy stuff here
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice *Ice::clone() const
{

}

void Ice::use(ICharacter &target)
{

}
