/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:15:45 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/24 21:15:47 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongCat();
		WrongCat(const WrongCat &src);
		WrongCat	&operator=(const WrongCat &src);
		~WrongCat();

		void	makeSound() const;
};

#endif
