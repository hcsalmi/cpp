/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:45:26 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/07 16:25:09 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : idea_idx(0) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &cpy) : idea_idx(0) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = cpy.ideas[i];
}

Brain &Brain::operator=(const Brain &cpy) {
	std::cout << "Brain assignment operator called" << std::endl;
	idea_idx = cpy.idea_idx;
	for (int i = 0; i < 100; i++)
		ideas[i] = cpy.ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(std::string idea)
{
	if (idea_idx > 99)
	{
		std::cout << "Brain is full" << std::endl;
		return ;
	}
	this->ideas[idea_idx] = idea;
	idea_idx++;
}

void Brain::printIdeas()
{
	for (int i = 0; i < idea_idx; i++)
		std::cout << ideas[i] << std::endl;
}
