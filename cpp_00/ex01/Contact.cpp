/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:23:05 by lsalmi            #+#    #+#             */
/*   Updated: 2023/12/08 18:23:07 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void		Contact::setFirstName(std::string first_name)
{
	this->_first_name = first_name;
}

void		Contact::setLastName(std::string last_name)
{
	this->_last_name = last_name;
}

void		Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

void		Contact::setPhoneNumber(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void		Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}

std::string	Contact::getFirstName(void)
{
	return (_first_name);
}

std::string	Contact::getLastName(void)
{
	return (_last_name);
}

std::string	Contact::getNickname(void)
{
	return (_nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (_phone_number);
}

std::string	Contact::getSecret(void)
{
	return (_secret);
}
