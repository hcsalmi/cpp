/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbroms <lbroms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:31:20 by lbroms            #+#    #+#             */
/*   Updated: 2023/10/05 18:49:58 by lbroms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:

		int					_bitsValues;
		static const int	_fractionalBits = 8;

	public:

		Fixed();
		Fixed(Fixed const & src);
		~Fixed();

		Fixed &		operator=( Fixed const & src );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

};

#endif
