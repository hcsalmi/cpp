/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:20:48 by lsalmi            #+#    #+#             */
/*   Updated: 2023/12/08 18:20:49 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::printContact(Contact contact)
{
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getSecret() << std::endl;
}

void	printField(std::string field, bool newline)
{
	if (field.length() > 10)
	{
		field.resize(9);
		field.append(".");
	}
	if (newline == 1)
		std::cout << std::setw(10) << field << std::endl;
	else
		std::cout << std::setw(10) << field << "|";
}

void	PhoneBook::printContactList(void)
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < _total; i++)
	{
		std::cout << std::setw(10) << i << "|";
		printField(_contact_list[i].getFirstName(), 0);
		printField(_contact_list[i].getLastName(), 0);
		printField(_contact_list[i].getNickname(), 1);
	}
}

void	PhoneBook::add(void)
{
	std::string input;
	static int	index;

	if (PhoneBook::_total < 8)
		PhoneBook::_total++;
	if (index == 8)
		index = 0;
	while (1)
	{
		if (std::cin.eof())
		{
			return ;
		}
		std::cout << "Enter first name:" << std::endl;
		std::getline(std::cin, input);
		if (input.length() > 0)
		{
			this->_contact_list[index].setFirstName(input);
			std::cin.sync();
			break ;
		}
	}

	while (1)
	{
		if (std::cin.eof())
		{
			return ;
		}
		std::cout << "Enter last name:" << std::endl;
		std::getline(std::cin, input);
		if (input.length() > 0)
		{
			this->_contact_list[index].setLastName(input);
			std::cin.sync();
			break ;
		}
	}

	while (1)
	{
		if (std::cin.eof())
		{
			return ;
		}
		std::cout << "Enter nickname:" << std::endl;
		std::getline(std::cin, input);
		if (input.length() > 0)
		{
			this->_contact_list[index].setNickname(input);
			std::cin.sync();
			break ;
		}
	}

	while (1)
	{
		if (std::cin.eof())
		{
			return ;
		}
		std::cout << "Enter phone number:" << std::endl;
		std::getline(std::cin, input);
		if (input.length() > 0)
		{
			this->_contact_list[index].setPhoneNumber(input);
			std::cin.sync();
			break ;
		}
	}

	while (1)
	{
		if (std::cin.eof())
		{
			return ;
		}
		std::cout << "Enter darkest secret:" << std::endl;
		std::getline(std::cin, input);
		if (input.length() > 0)
		{
			this->_contact_list[index].setSecret(input);
			std::cin.sync();
			break ;
		}
	}
	index++;
}

void	PhoneBook::search(void)
{
	std::string	input;
	int			index;

	if (_total == 0)
	{
		std::cout << "The phonebook is empty" << std::endl;
		return ;
	}
	printContactList();
	std::cout << "Enter index:" << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		return ;
	}
	for (unsigned long i = 0; i < input.length(); i++)
	{
		if (std::isdigit(input[i]) == 0)
		{
			std::cout << "Index invalid" << std::endl;
			return ;
		}
	}
	index = std::atoi(input.c_str());
	if (index < 0 || index >= _total)
	{
		std::cout << "Index invalid" << std::endl;
			return ;
	}
	else
		printContact(_contact_list[index]);
}

void	PhoneBook::exit(void)
{
	std::cout << "Exiting" << std::endl;
}