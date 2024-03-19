/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:38:54 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/19 17:38:56 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./scalarconverter <literal>" << std::endl;
		return (1);
	}
	ScalarConverter converter;
	converter.convert(argv[1]);
	return (0);
}