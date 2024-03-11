/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:35:05 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/08 15:35:07 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("no target")
{
	std::cout << "Default ShrubberyCreationForm was constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm was constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName(), src.getGradetoSign(), src.getGradetoExecute()), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm copy was constructed" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm was shredded" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &src)
		this->_target = src.getTarget();
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}


void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignedStatus() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradetoExecute())
		throw AForm::GradeTooLowException();

	std::string filename = this->getTarget();
	filename = filename.append("_shrubbery");
	std::ofstream outfile(filename);
	if (!outfile.is_open())
		throw ShrubberyCreationForm::FileOpenFailException();

	outfile << std::endl;

	outfile << "     .o00o" << std::endl;
	outfile << "    o000000oo" << std::endl;
	outfile <<   " 00000000000o" << std::endl;
	outfile <<  " 00000000000000" << std::endl;
	outfile << " oooooo  00000000  o88o" << std::endl;
	outfile << " ooOOOOOOOoo  ```00  888888" << std::endl;
	outfile << "OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
	outfile << "oOOOOOOOOOO .QQQQQQQQQQ/.88'" << std::endl;
	outfile << "OOOOOOOOOO .QQQQQQQQQQ/ /q" << std::endl;
	outfile << "OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
	outfile << " OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
	outfile << "  OO:F_P:O `QQQ/  /Q'" << std::endl;
	outfile << "     .l  |  //" << std::endl;
	outfile << "      \\l|_// __/" << std::endl;
	outfile << "       \\ _ /" << std::endl;
	outfile << "        / l/" << std::endl;
	outfile << "        | O|" << std::endl;
	outfile << "      /l l_//l " << std::endl;
	outfile << "   __/  / `- l_" << std::endl;
	outfile << " __/l__  l__  o  l_____" << std::endl;

	outfile.close();
}
