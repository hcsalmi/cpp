/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:00:21 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/06 19:00:23 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("some form"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
	std::cout << "\e[0;32mDefault Form was constructed\e[0m" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),
			_signed(false)
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "\e[0;32mCustom Form was constructed, name: " << this->_name << ", grade to sign: " <<
			_gradeToSign << ", grade to execute: " << _gradeToExecute << "\e[0m" << std::endl;
}

Form::Form(const Form &src) : _name(src.getName()), _gradeToSign(src.getGradetoSign()),
			_gradeToExecute(src.getGradetoExecute()), _signed(src.getSignedStatus())
{
	std::cout << "\e[0;32mForm copy was constructed\e[0m" << std::endl;
}

Form	&Form::operator=(const Form &src)
{
	std::cout << "\e[0;32mForm copy assignment operator called\e[0m" << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "\e[0;31mForm was shredded\e[0m" << std::endl;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else if (this->_signed == true)
		throw Form::FormAlreadySignedException();
	else
		this->_signed = true;
}

std::string Form::getName() const
{
	return (this->_name);
}

bool	Form::getSignedStatus() const
{
	return (this->_signed);
}

int	Form::getGradetoSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradetoExecute() const
{
	return (this->_gradeToExecute);
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Name:\t\t\t" << form.getName() << std::endl <<
	"Signed status:\t\t" << form.getSignedStatus() << std::endl <<
	"Grade to sign:\t\t" << form.getGradetoSign() << std::endl <<
	"Grade to execute:\t" << form.getGradetoExecute() << std::endl;
	return (os);
}
