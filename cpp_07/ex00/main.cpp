/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:42:12 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/22 17:42:14 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main( void )
{
	std::cout << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );

	std::cout << "\e[0;36m" << "a = " << a << ", b = " << b << "\e[0m" << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "\e[0;36m" << "c = " << c << ", d = " << d << "\e[0m" << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	std::cout << std::endl;

	char c1 = 'a';
	char c2 = 'b';
	::swap(c1, c2);
	std::cout << "\e[0;36m" << "c1 = " << c1 << ", c2 = " << "\e[0m" << c2 << std::endl;
	std::cout << "min(c1, c2) = " << ::min(c1, c2) << std::endl;
	std::cout << "max(c1, c2) = " << ::max(c1, c2) << std::endl;
	std::cout << std::endl;

	float f1 = 1.1;
	float f2 = 2.2;
	::swap(f1, f2);
	std::cout << "\e[0;36m" << "f1 = " << f1 << ", f2 = " << f2 << "\e[0m" << std::endl;
	std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
	std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;
	std::cout << std::endl;

	float f3 = 1.1;
	float f4 = 1.1;
	::swap(f1, f2);
	std::cout << "\e[0;36m" << "f3 = " << f3 << ", f4 = " << f4 << "\e[0m" << std::endl;
	std::cout << "\e[0;36m" << "&f3 = " << &f3 << ", &f4 = " << &f4 << "\e[0m" << std::endl;
	std::cout << "min(f3, f4) = " << ::min(f3, f4) << std::endl;
	std::cout << "min at address = " << &(::min(f3, f4)) << std::endl;
	std::cout << std::endl;
	std::cout << "max(f3, f4) = " << ::max(f3, f4) << std::endl;
	std::cout << "max at address " << &(::max(f3, f4)) << std::endl;
	std::cout << std::endl;

	return (0);
}
