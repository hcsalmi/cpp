/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbroms <lbroms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:31:27 by lbroms            #+#    #+#             */
/*   Updated: 2023/10/05 22:23:56 by lbroms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_bitsValues = 0;
}

Fixed::Fixed( int const value )
{
	std::cout << "Int constructor called" << std::endl;
	this->_bitsValues = value << this->_fractionalBits;
}

Fixed::Fixed( float const value )
{
	std::cout << "Float constructor called" << std::endl;
	this->_bitsValues = roundf(value * (1 << this->_fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &		Fixed::operator=( Fixed const & src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_bitsValues = src.getRawBits();
	return *this;
}

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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_bitsValues;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_bitsValues = raw;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
    o << i.toFloat();
    return o;
}
 