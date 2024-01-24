/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:28:52 by esirnio           #+#    #+#             */
/*   Updated: 2023/11/26 16:30:28 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	protected:
		std::string type;
	public:
		WrongCat();
		WrongCat(const WrongCat &cpy);
		WrongCat &operator=(const WrongCat &cpy);
		~WrongCat();
		void makeSound();
};

#endif
