/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:23:23 by lsalmi            #+#    #+#             */
/*   Updated: 2023/12/08 18:23:26 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	PhoneBook	phonebook;
	std::string	command;

	(void)argv;
	if (argc != 1)
	{
		std::cout << "usage ./phonebook" << std::endl;
		return (0);
	}
	while (1)
	{
		std::cout << "Enter command:" << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "Thank you for using the phonebook" << std::endl;
			return (0);
		}
		if (command == "EXIT")
		{
			phonebook.exit();
			return (0);
		}
		else if (command == "ADD")
		{
			phonebook.add();
		}
		else if (command == "SEARCH")
		{
			phonebook.search();
		}
		else
			std::cout << "Command invalid. Try ADD, SEARCH, or EXIT." << std::endl;
		std::cin.clear();
		command.clear();
	}
}
