/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:13:05 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/22 17:13:07 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	protected:
		std::string	_type;

	public:
		Dog();
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		~Dog();

		void	makeSound() const;
};

#endif