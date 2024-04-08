/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:32:09 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/26 18:32:11 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T 				*_array;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &src);
		~Array();

		Array<T> &operator=(const Array<T> &src);
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		unsigned int	size() const;
};

#endif
