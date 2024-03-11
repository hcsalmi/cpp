/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:35:26 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/08 15:35:28 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("no target")
{
	std::cout << "Default RobotomyRequestForm was constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm was constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src.getName(), src.getGradetoSign(), src.getGradetoExecute()), _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm copy was constructed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm was shredded" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &src)
		this->_target = src.getTarget();
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static int i;
	if (this->getSignedStatus() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradetoExecute())
		throw AForm::GradeTooLowException();
	std::cout << "BZZzzZZZ Whirrrrr" << std::endl;
	if (i % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Failed to robotomize " << this->_target << std::endl;
	i++;
}
