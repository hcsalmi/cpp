/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:49:01 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/08 13:48:36 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		std::string type;
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &cpy);
		Dog &operator=(const Dog &cpy);
		~Dog();
		void makeSound() const;
		void setIdea(std::string idea);
		void printIdeas();
};

#endif