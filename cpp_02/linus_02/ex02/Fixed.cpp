/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbroms <lbroms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:31:27 by lbroms            #+#    #+#             */
/*   Updated: 2023/10/06 15:55:58 by lbroms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*constructors and destructor and copy assingment operator*/

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->_bitsValues = 0;
}

Fixed::Fixed( int const value )
{
	//std::cout << "Int constructor called" << std::endl;
	this->_bitsValues = value << this->_fractionalBits;
}

Fixed::Fixed( float const value )
{
	//std::cout << "Float constructor called" << std::endl;
	this->_bitsValues = roundf(value * (1 << this->_fractionalBits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	//std::cout << "Copy constructor called" << std::endl;
	//maybe could do *this = src; but apparently using the = operator isnt cool in constructors
	this->_bitsValues = src.getRawBits();
}

Fixed &		Fixed::operator=( Fixed const & src )
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_bitsValues = src.getRawBits();
	return *this;
}


/*member functions for fixed point conversions*/

float Fixed::toFloat( void ) const
{
	return (float)this->_bitsValues / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->_bitsValues >> this->_fractionalBits;
}

int	Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_bitsValues;
}

void	Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_bitsValues = raw;
}


/*operator overloads*/

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
    o << i.toFloat();
    return o;
}

bool		Fixed::operator>( Fixed const & rhs ) const
{
	return this->_bitsValues > rhs.getRawBits();
}

bool		Fixed::operator<( Fixed const & rhs ) const
{
	return this->_bitsValues < rhs.getRawBits();
}

bool		Fixed::operator>=( Fixed const & rhs ) const
{
	return this->_bitsValues >= rhs.getRawBits();
}

bool		Fixed::operator<=( Fixed const & rhs ) const
{
	return this->_bitsValues <= rhs.getRawBits();
}

bool		Fixed::operator==( Fixed const & rhs ) const
{
	return this->_bitsValues == rhs.getRawBits();
}

bool		Fixed::operator!=( Fixed const & rhs ) const
{
	return this->_bitsValues != rhs.getRawBits();
}

Fixed		Fixed::operator+( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed		Fixed::operator-( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed		Fixed::operator*( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &		Fixed::operator--( void )
{
	this->_bitsValues--;
	return *this;
}

Fixed		Fixed::operator--( int )
{
	Fixed temp(*this);
	this->_bitsValues--;
	return temp;
}

Fixed &		Fixed::operator++( void )
{
	this->_bitsValues++;
	return *this;
}

Fixed		Fixed::operator++( int )
{
	Fixed temp(*this);
	this->_bitsValues++;
	return temp;
}


/*mins and maxes*/

Fixed &		Fixed::min( Fixed & lhs, Fixed & rhs )
{
	if (lhs < rhs)
		return lhs;
	else
		return rhs;
}

Fixed &		Fixed::max( Fixed & lhs, Fixed & rhs )
{
	if (lhs > rhs)
		return lhs;
	else
		return rhs;
}

const Fixed &	Fixed::min( Fixed const & lhs, Fixed const & rhs )
{
	if (lhs < rhs)
		return lhs;
	else
		return rhs;
}

const Fixed &	Fixed::max( Fixed const & lhs, Fixed const & rhs )
{
	if (lhs > rhs)
		return lhs;
	else
		return rhs;
}
