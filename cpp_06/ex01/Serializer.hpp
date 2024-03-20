/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:48:32 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/20 16:48:35 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# define	RED			"\e[0;31m"
# define	GREEN		"\e[0;32m"
# define	BLUE		"\e[0;34m"
# define	MAG			"\e[0;35m"
# define	CYAN		"\e[0;36m"
# define	COLRESET	"\e[0m"

#include <iostream>

struct Data
{
	std::string	str;
	int			n;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();

		Serializer &operator=(const Serializer &src);

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);

};

#endif