/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:59:35 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/05 19:59:37 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("anonymous"), _grade(150)
{
	std::cout << "Default Bureaucrat was constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		this->_grade = grade;
		std::cout << "\e[0;32mBureaucrat of grade " << grade << " was constructed\e[0m" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->_grade = src._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mBureaucrat destructor called\e[0m" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "\e[0;31mBureaucrat getting demoted...\e[0m" << std::endl;
	if (this->_grade < 150)
	{
		this->_grade++;
	}
	else
	{
		throw GradeTooLowException();
	}
}

void	Bureaucrat::incrementGrade()
{
	std::cout << "\e[0;36mBureaucrat getting promoted...\e[0m" << std::endl;
	if (this->_grade > 1)
	{
		this->_grade--;
	}
	else
	{
		throw GradeTooHighException();
	}
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std:: cout << "\e[0;36m" << this->_name << " signed " << form.getName() << "\e[0m" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "\e[0;31m" << this->_name << " couldn't sign " << form.getName() << " because: " << e.what() << "\e[0m" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}
