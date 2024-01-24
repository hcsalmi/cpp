/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:13:15 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/22 17:13:16 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
	protected:
		std::string	_type;

	public:
		Cat();
		Cat(const Cat &src);
		Cat	&operator=(const Cat &src);
		~Cat();

		void	makeSound() const;
};

#endif
