/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:27:02 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/06 19:27:04 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _bitValue(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
//	std::cout << "Int constructor called" << std::endl;
	this->_bitValue = nbr << this->_fractionalBits;
}

Fixed::Fixed(const float nbr)
{
//	std::cout << "Float constructor called" << std::endl;
	this->_bitValue = roundf(nbr * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
//	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

Fixed::~Fixed(void)
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
}

int		Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_bitValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_bitValue = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_bitValue / (1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_bitValue >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &nbr)
{
	os << nbr.toFloat();
	return (os);
}

/*New content since last exercise*/

bool	Fixed::operator>(const Fixed &rhs) const
{
	if (this->_bitValue > rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	if (this->_bitValue < rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	if (this->_bitValue >= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	if (this->_bitValue <= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	if (this->_bitValue == rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed:: operator!=(const Fixed &rhs) const
{
	if (this->_bitValue != rhs.getRawBits())
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);

	this->_bitValue++;
	return (temp);
}

Fixed	&Fixed::operator++(void)
{
	this->_bitValue++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);

	this->_bitValue--;
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	this->_bitValue--;
	return (*this);
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}
