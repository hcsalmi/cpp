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

bool	ScalarConverter::isChar(const std::string &literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(const std::string &literal)
{
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && literal[i] == '-')
		{
			i++;
			continue ;
		}
		if (isdigit(literal[i]) == 0)
			return (false);
	}

	if (stoi(literal) > INT_MAX || stoi(literal) < INT_MIN)
		return (false);
	return (true);
}

bool	ScalarConverter::isFloat(const std::string &literal)
{
	int hasDecimal = 0;
	int hasF = 0;

	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && literal[i] == '-')
		{
			i++;
			continue ;
		}
		if (literal[i] == 'f' && i == 0)
			return (false);
		if (literal[i] == '.')
			hasDecimal++;
		else if (literal[i] == 'f')
			hasF++;
		else if (isdigit(literal[i]) == 0)
			return (false);
	}
	if (hasDecimal == 1 && hasF == 1 && literal[literal.length() - 1] == 'f')
		return (true);
	return (false);
}

bool	ScalarConverter::isDouble(const std::string &literal)
{
	int hasDecimal = 0;

	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && literal[i] == '-')
		{
			i++;
			continue ;
		}
		if (literal[i] == '.')
			hasDecimal++;
		else if (isdigit(literal[i]) == 0)
			return (false);
	}
	if (hasDecimal == 1)
		return (true);
	return (false);
}

bool	ScalarConverter::isPseudoLit(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
		literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	return (false);
}

char	ScalarConverter::checkType(const std::string &literal)
{
	if (isChar(literal) == true)
		return ('c');
	else if (isInt(literal) == true)
		return ('i');
	else if (isFloat(literal) == true)
		return ('f');
	else if (isDouble(literal) == true)
		return ('d');
	else if (isPseudoLit(literal) == true)
		return ('p');
	return ('1');
}

void	ScalarConverter::printChar(char ch)
{

	if (isprint(ch) == 0)
		std::cerr << "Character not displayable" << std::endl;
	else
		std::cout << "'" << ch << "'" << std::endl;
}

void	ScalarConverter::printInt(int i, long double value)
{
	if (value > INT_MAX || value < INT_MIN)
		std::cerr << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
}

void	ScalarConverter::printFloat(float f, long double value)
{
	if (value > FLT_MAX || value < -FLT_MAX)
		std::cerr << "impossible" << std::endl;
	else
	{
		if (f - static_cast<int>(f) == 0)
			std::cout << f << ".0f" << std::endl;
		else
			std::cout << f << std::endl;
	}
}

void	ScalarConverter::printDouble(double d, long double value)
{
	if (value > DBL_MAX || value < -DBL_MAX)
		std::cerr << "impossible" << std::endl;
	else
	{
		if (d - static_cast<int>(d) == 0)
			std::cout << d << ".0" << std::endl;
		else
			std::cout << d << std::endl;
	}
}

void	ScalarConverter::printPseudoLit(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << std::endl;
	std::cout << "double: " << literal << std::endl;
}

void	ScalarConverter::print(long double value)
{
	std::cout << "to char: ";
	printChar(static_cast<char>(value));
	std::cout << "to int: ";
	printInt(static_cast<int>(value), value);
	std::cout << "to float: ";
	printFloat(static_cast<float>(value), value);
	std::cout << "to double: ";
	printDouble(static_cast<double>(value), value);
}

void	ScalarConverter::convert(const std::string &literal)
{
	char type = checkType(literal);
	std::cout << CYAN << "Converting literal: " << literal << COLRESET << std::endl;

	if (type == 'c')
		print(literal[0]);
	else if (type == 'i')
		print(std::stod(literal));
	else if (type == 'f')
		print(std::stod(literal));
	else if (type == 'd')
		print(std::stod(literal));
	else if (type == 'p')
		printPseudoLit(literal);
	else
		std::cerr << RED << "Value cannot be converted" << COLRESET << std::endl;
}
