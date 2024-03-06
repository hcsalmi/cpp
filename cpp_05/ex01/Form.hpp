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

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form();
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		std::string	getName() const;
		bool		getSignedStatus() const;
		const int	getGradetoSign() const;
		const int	getGradetoExecute() const;
		void		beSigned(const Bureaucrat &bureaucrat);

		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw() { return "Grade too low"; }
		};

		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw() { return "Grade too high"; }
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
