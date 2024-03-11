/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:35:14 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/08 15:35:16 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		std::string getTarget() const;
		void	execute(Bureaucrat const &executor) const;

		class FileOpenFailException : public std::exception {
			public:
				const char *what(void) const throw() { return "Failed to open file"; }
		};
};

#endif
