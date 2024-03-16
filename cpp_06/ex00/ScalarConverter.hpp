/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:20:55 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/16 18:20:58 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <float.h>

# define	RED			"\033[0;31m"
# define	GREEN		"\033[0;32m"
# define	BLUE		"\033[0;34m"
# define	MAG			"\033[0;35m"
# define	CYAN		"\036[0;35m"
# define	COLRESET	"\033[0m"

class ScalarConverter
{
	private:
		static char	checkType(const std::string &literal);
		static bool	isChar(const std::string &literal);
		static bool	isInt(const std::string &literal);
		static bool	isFloat(const std::string &literal);
		static bool	isDouble(const std::string &literal);
		static bool	isPseudoLit(const std::string &literal);

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &src);

		static void	convert(const std::string &literal);

};


#endif

/*


		void displayChar(char ch, long double c);
		void displayInt(int i, long double c);
		void displayFloat(float f, long double c);
		void displayDouble(double d, long double c);
		void displayPseudo(std::string parameter);
 */