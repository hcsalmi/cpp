/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:00:12 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/06 19:00:14 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_signed;

	public:
		Form();
		Form(const Form &src);
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form &operator=(const Form &src);
		~Form();

		std::string	getName() const;
		bool		getSignedStatus() const;
		int			getGradetoSign() const;
		int			getGradetoExecute() const;

		void		beSigned(const Bureaucrat &bureaucrat);

		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw() { return "Grade too low"; }
		};

		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw() { return "Grade too high"; }
		};

		class FormAlreadySignedException : public std::exception {
			public:
				const char *what(void) const throw() { return "Form already signed"; }
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
