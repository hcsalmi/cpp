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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\n";
	{
		try
		{
			Bureaucrat	first("Can't do", 149);
			Bureaucrat	second("Can Do", 8);
			std::cout << "\n";
			std::cout << first;
			std::cout << second << std::endl;

			ShrubberyCreationForm	shrub("backyard");
			std::cout << shrub << std::endl;

			first.signForm(shrub);
			first.executeForm(shrub);
			std::cout << "\n";
			second.signForm(shrub);
			second.executeForm(shrub);
			std::cout << "\n";
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
			Bureaucrat	first("Can't do", 149);
			Bureaucrat	second("Can Do", 8);
			std::cout << "\n";
			std::cout << first;
			std::cout << second << std::endl;

			RobotomyRequestForm		robo("The Chosen One");
			RobotomyRequestForm		robo2("Another Victim");
			std::cout << robo << std::endl;

			first.signForm(robo);
			first.executeForm(robo);
			std::cout << "\n";
			second.signForm(robo);
			second.executeForm(robo);
			std::cout << "\n";
			second.signForm(robo2);
			second.executeForm(robo2);
			std::cout << "\n";
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
			Bureaucrat	first("Can't do", 149);
			Bureaucrat	second("Can Do", 1);
			std::cout << "\n";
			std::cout << first;
			std::cout << second << std::endl;

			PresidentialPardonForm	pres("I Ain't Done Nothing");
			std::cout << pres << std::endl;

			first.signForm(pres);
			first.executeForm(pres);
			std::cout << "\n";
			second.signForm(pres);
			second.executeForm(pres);
			std::cout << "\n";
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n ------------------------------------- \n" << std::endl;

	return (0);
}
