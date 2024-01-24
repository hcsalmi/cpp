/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:48:17 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/07 19:19:12 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		std::string type;
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &cpy);
		Cat &operator=(const Cat &cpy);
		~Cat();
		void makeSound();
};

#endif