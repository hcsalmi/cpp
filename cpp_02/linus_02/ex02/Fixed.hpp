/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbroms <lbroms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:31:20 by lbroms            #+#    #+#             */
/*   Updated: 2023/11/13 17:02:23 by lbroms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
	
		int					_bitsValues;
		static const int	_fractionalBits = 8;

	public:

		Fixed();
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const & src );
		~Fixed();

		Fixed &				operator=( Fixed const & src );
		
		int 				getRawBits( void ) const;
		void 				setRawBits( int const raw );
		float 				toFloat( void ) const;
		int 				toInt( void ) const;

		bool				operator>( Fixed const & rhs ) const;
		bool				operator<( Fixed const & rhs ) const;
		bool				operator>=( Fixed const & rhs ) const;
		bool				operator<=( Fixed const & rhs ) const;
		bool				operator==( Fixed const & rhs ) const;
		bool				operator!=( Fixed const & rhs ) const;
		Fixed				operator+( Fixed const & rhs ) const;
		Fixed				operator-( Fixed const & rhs ) const;
		Fixed				operator*( Fixed const & rhs ) const;
		Fixed				operator/( Fixed const & rhs ) const;
		Fixed &				operator--( void );
		Fixed				operator--( int );
		Fixed &				operator++( void );
		Fixed				operator++( int );
		static Fixed &		min( Fixed & lhs, Fixed & rhs );
		static const Fixed &		min( Fixed const & lhs, Fixed const & rhs );
		static Fixed &		max( Fixed & lhs, Fixed & rhs );
		static const Fixed &		max( Fixed const & lhs, Fixed const & rhs );

};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif
