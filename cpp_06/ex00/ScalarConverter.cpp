/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:20:49 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/16 18:20:51 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	//std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	//std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
	//std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	// std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	(void)src;
	return (*this);
}




char	ScalarConverter::checkType(const std::string &literal)
{

}

void	ScalarConverter::convert(const std::string &literal)
{
	char type = checkType(literal);

}




//This with function pointers?
/*
void	ScalarConverter::convert(std::string parameter) {
	char c = check_parameter(parameter);
	switch (c)
	{
		case 'c':
			display(parameter[0], parameter);
			break;
		case 'i':
			display(std::stod(parameter), parameter);
			break;
		case 'f':
			display(std::stod(parameter), parameter);
			break;
		case 'd':
			display(std::stod(parameter), parameter);
			break;
		case 'p':
			displayPseudo(parameter);
			break;
		default:
			throw (std::exception());
	}
} */

//Function pointer model
/*
AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *(*form_ptr[])(const std::string target) = {&createShrubbery, &createRobotomy, &createPresident};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "\e[0;36mIntern creates " << formName << "\e[0m" << std::endl;
			return form_ptr[i](target);
		}
	}
	std::cout << "\e[0;31mIntern cannot create form: " << formName << "\e[0m" << std::endl;
	return (nullptr);
}
 */