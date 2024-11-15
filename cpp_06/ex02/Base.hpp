/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:49:01 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/22 14:49:05 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

# define	RED			"\e[0;31m"
# define	GREEN		"\e[0;32m"
# define	MAG			"\e[0;35m"
# define	CYAN		"\e[0;36m"
# define	COLRESET	"\e[0m"

class Base
{
	public:
		virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
