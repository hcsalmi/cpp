/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:20:25 by lsalmi            #+#    #+#             */
/*   Updated: 2023/12/30 16:20:27 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of the string: \t\t\t" << &str << std::endl;
	std::cout << "Memory address stored in POINTER to string: \t" << stringPTR << std::endl;
	std::cout << "Memory address stored in REFERENCE to string: \t" << &stringREF << std::endl;

	std::cout << "\nValue of the string: \t\t" << str << std::endl;
	std::cout << "Value pointed to by POINTER: \t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by REFERENCE: \t" << stringREF <<  std::endl;

	return (0);
}
