/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:59:18 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/05 19:59:20 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n";
	{
		try
		{
			std::cout << "Trying to create a default form..." << std::endl;
			Form a;
			std::cout << a << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n ------------------------------------- \n" << std::endl;
	{
		try
		{
			std::cout << "Trying to create a default form..." << std::endl;
			Form a;
			std::cout << a << std::endl;
			std::cout << "Copying a form..." << std::endl;
			Form b(a);
			std::cout << b << std::endl;
			std::cout << "Testing copy assignment operator..." << std::endl;
			Form c;
			c = a;
			std::cout << c << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n ------------------------------------- \n" << std::endl;
	{
		try
		{
			std::cout << "Trying to create a form with parameters..." << std::endl;
			Form a("Too low", 10, 151);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n ------------------------------------- \n" << std::endl;
	{
		try
		{
			std::cout << "Trying to create a form with parameters..." << std::endl;
			Form a("Too high", 0, 150);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n ------------------------------------- \n" << std::endl;
	{
		try
		{
			std::cout << "Trying to create a form with parameters..." << std::endl;
			Form a("TenTen", 10, 10);
			std::cout << a << std::endl;
			Bureaucrat b("George the Ninth", 9);
			std::cout << b << std::endl;
			b.signForm(a);
			std::cout << "\n" << a << std::endl;
			b.signForm(a);
			std::cout << "\n" << a << std::endl;

			std::cout << "Trying to create a form with parameters..." << std::endl;
			Form c("EightEight", 8, 8);
			std::cout << "\n" << c << std::endl;
			b.signForm(c);
			std::cout << "\n" << c << std::endl;

		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
