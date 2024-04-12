/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:44:27 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/22 17:44:29 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

template <typename T>
T &min(T &a, T &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T &max(T &a, T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif



/*

swap: Swaps the values of two given arguments. Does not return anything.

min: Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one.

max: Compares the two values passed in its arguments and returns the greatest one.
If the two of them are equal, then it returns the second one.

These functions can be called with any type of argument. The only requirement is
that the two arguments must have the same type and must support all the comparison
operators.

*/