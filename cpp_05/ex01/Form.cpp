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

Form::Form() : _name("some form"), _signed(false), _gradeToExecute(0), _gradeToSign(0)
{
	std::cout << "Default Form was constructed" << std::endl;
}

Form::Form(const Form &src) : _name(src.getName()),
			_signed(src.getSignedStatus()), _gradeToExecute(src.getGradetoExecute()),
			_gradeToSign(src.getGradetoSign())
{
	std::cout << "Form copy was constructed" << std::endl;
}

Form	&Form::operator=(const Form &src)	//throw something here?
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form was shredded" << std::endl;
}