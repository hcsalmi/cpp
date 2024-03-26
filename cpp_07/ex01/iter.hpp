/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:52:05 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/26 17:52:07 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, std::size_t length, void(*operation)(T))
{
	for (size_t i = 0; i < length; i++)
	{
		operation(array[i]);
	}
}

#endif

/*

Implement a function template iter that takes 3 parameters and returns nothing.

• The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be call on every element of the array.

Turn in a main.cpp file that contains your tests. Provide enough code to generate a
test executable.
Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.

*/