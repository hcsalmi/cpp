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
#include "Form.hpp"

int main()
{
	std::cout << "\n";
	{
		try
		{
			std::cout << "Trying for a new bureaucrat..." << std::endl;
			Bureaucrat a("Regular guy", 2);
			std::cout << a << std::endl;
			a.incrementGrade();
			std::cout << a << std::endl;
			a.decrementGrade();
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
			std::cout << "Trying for a new bureaucrat..." << std::endl;
			Bureaucrat	a("Too high", 0);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::cout << "Trying for a new bureaucrat..." << std::endl;
			Bureaucrat	a("Too low", 151);
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
			std::cout << "Trying for a new bureaucrat..." << std::endl;
			Bureaucrat a("Top brass", 1);
			std::cout << a << std::endl;
			a.incrementGrade();
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
			std::cout << "Trying for a new bureaucrat..." << std::endl;
			Bureaucrat a("Bottom feeder", 150);
			std::cout << a << std::endl;
			a.decrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n ------------------------------------- \n" << std::endl;

	return (0);
}
