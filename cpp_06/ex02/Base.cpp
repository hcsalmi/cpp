/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:55:28 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/20 18:55:32 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}

Base *generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int i = std::rand() % 3;

	if (i == 0)
	{
		std::cout << "Generated A" << std::endl;
		return (new A);
	}
	if (i == 1)
	{
		std::cout << "Generated B" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "Generated C" << std::endl;
		return (new C);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "Pointing to A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "Pointing to B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "Pointing to C" << std::endl;
	else
		std::cout << RED << "Could not determine type" << COLRESET << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &temp = dynamic_cast<A&>(p);
		std::cout << "Reference to A" << std::endl;
		static_cast<void>(temp);
		return ;
	}
	catch(const std::exception &e) {}
	try
	{
		B &temp = dynamic_cast<B&>(p);
		std::cout << "Reference to B" << std::endl;
		static_cast<void>(temp);
		return ;
	}
	catch(const std::exception &e) {}
	try
	{
		C &temp = dynamic_cast<C&>(p);
		std::cout << "Reference to C" << std::endl;
		static_cast<void>(temp);
		return ;
	}
	catch(const std::exception &e) {}
	std::cout << RED << "Cannot identify base" << COLRESET << std::endl;
}
