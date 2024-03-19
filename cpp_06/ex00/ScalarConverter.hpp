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

# define	RED			"\e[0;31m"
# define	GREEN		"\e[0;32m"
# define	BLUE		"\e[0;34m"
# define	MAG			"\e[0;35m"
# define	CYAN		"\e[0;36m"
# define	COLRESET	"\e[0m"

class ScalarConverter
{
	private:
		static char	checkType(const std::string &literal);
		static bool	isChar(const std::string &literal);
		static bool	isInt(const std::string &literal);
		static bool	isFloat(const std::string &literal);
		static bool	isDouble(const std::string &literal);
		static bool	isPseudoLit(const std::string &literal);

		static void	print(long double value);
		static void	printChar(char ch);
		static void	printInt(int i, long double value);
		static void	printFloat(float f, long double value);
		static void	printDouble(double d, long double value);
		static void	printPseudoLit(const std::string &literal);

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