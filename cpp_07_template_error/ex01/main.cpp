/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:59 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/26 18:07:00 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void	printElement(T element)
{
	std::cout << element << std::endl;
}

int main()
{
	std::cout << std::endl;
	{
		int array[] = {1, 2, 3, 4, 5};

		std::cout << "\e[0;36m" << "Printing int array: " << "\e[0m" << std::endl;
		iter(array, 5, printElement);
		std::cout << std::endl;
	}
	{
		double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};

		std::cout << "\e[0;36m" << "Printing double array: " << "\e[0m" << std::endl;
		iter(array, 5, printElement);
		std::cout << std::endl;
	}
	{
		std::string array[] = {"one", "two", "three", "four", "five"};

		std::cout << "\e[0;36m" << "Printing string array: " << "\e[0m" << std::endl;
		iter(array, 5, printElement);
		std::cout << std::endl;
	}

	return (0);
}
