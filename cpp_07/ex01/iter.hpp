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
