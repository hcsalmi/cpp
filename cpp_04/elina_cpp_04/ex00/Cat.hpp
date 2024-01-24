/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:48:17 by esirnio           #+#    #+#             */
/*   Updated: 2023/11/26 16:16:10 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
	protected:
		std::string type;
	public:
		Cat();
		Cat(const Cat &cpy);
		Cat &operator=(const Cat &cpy);
		~Cat();
		void makeSound();
};

#endif