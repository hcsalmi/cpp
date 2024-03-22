/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:55:51 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/20 18:55:54 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base *type;

	std::cout << std::endl;
	std::cout << GREEN << "Generating base..." << COLRESET << std::endl;
	type = generate();
	std::cout << CYAN << "Identifying base (pointer)..." << COLRESET << std::endl;
	identify(type);
	std::cout << MAG << "Identifying base (reference)..." << COLRESET << std::endl;
	identify(*type);
	delete type;
	return (0);
}
