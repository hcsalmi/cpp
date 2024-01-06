/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:37:07 by lsalmi            #+#    #+#             */
/*   Updated: 2024/01/02 19:37:27 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	ft_replace(std::string content, std::string s1, std::string s2)
{
	size_t	found;
	size_t	i = 0;

	while (content[i] != '\0')
	{
		found = content.find(s1);
		if (found == std::string::npos)
			return (content);
		content.erase(found, s1.length());
		content.insert(found, s2);
		i++;
	}
	return (content);

}

int	main(int argc, char **argv)
{
	std::ifstream	read_file;
	std::ofstream	write_file;
	std::string		new_file_name;
	std::string		content;

	if (argc != 4)
	{
		std::cout << "Usage ./replace <file> <old_string> <new_string>" << std::endl;
		return (0);
	}
	read_file.open(argv[1]);
	if (!read_file.is_open())
	{
		std::cout << "Failed to open file for reading" << std::endl;
		return (1);
	}
	new_file_name = argv[1];
	new_file_name = new_file_name.append(".replace");
	write_file.open(new_file_name);
	if (!write_file.is_open())
	{
		std::cout << "Failed to open file for writing" << std::endl;
		return (1);
	}
	std::getline(read_file, content, '\0');
	write_file << ft_replace(content, argv[2], argv[3]);
	read_file.close();
	write_file.close();
	return (0);
}
