/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:35:46 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/08 15:35:48 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("no target")
{
	std::cout << "PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm was constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src.getName(), src.getGradetoSign(), src.getGradetoExecute()), _target(src.getTarget())
{
	std::cout << "PresidentialPardonForm copy was constructed" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm was shredded" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &src)
		this->_target = src.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignedStatus() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradetoExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

