/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:17:19 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/24 21:17:20 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "default idea";
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
}

Brain	&Brain::operator=(const Brain &src)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = src._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(size_t index, std::string idea)
{
	if (index > 99)
	{
		std::cout << "Index outside brain capacity" << std::endl;
	}
	else
		this->_ideas[index] = idea;
}

void	Brain::getIdea(size_t index) const
{
	if (index > 99)
	{
		std::cout << "Index outside brain capacity" << std::endl;
	}
	else
	{
		std::cout << this->_ideas[index] << std::endl;
	}
}
