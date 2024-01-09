/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:27:11 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/06 19:27:13 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_bitValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed &src);
		~Fixed(void);
		Fixed &operator=(const Fixed &src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		//new stuff
};

//Defines the behavior of streaming a Fixed object into an output stream.
//Returns a reference to the output stream to support chaining.
//Parameters: the output stream (os),
//a const reference to a Fixed object (nbr) that will be streamed.
std::ostream &operator<<(std::ostream &os, const Fixed &nbr);

#endif
