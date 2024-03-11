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

class AForm
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_signed;

	public:
		AForm();
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		std::string	getName() const;
		bool		getSignedStatus() const;
		int			getGradetoSign() const;
		int			getGradetoExecute() const;

		void			beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

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

		class FormNotSignedException : public std::exception {
			public:
				const char *what(void) const throw() { return "Form not signed"; }
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
