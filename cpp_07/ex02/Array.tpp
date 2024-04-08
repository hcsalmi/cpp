/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:32:09 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/26 18:32:11 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _array(nullptr)
{
	std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n])
{
	std::cout << "Array size constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &src) : _size(src._size)
{
	std::cout << "Array copy constructor called" << std::endl;
	if (this->_size != 0)
	{
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->_array[i] = src._array[i];
		}
	}
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;
	if (this->_array != nullptr)
		delete[] (this->_array);
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &src)
{
	std::cout << "Array copy assignment operator called" << std::endl;
	if (this != &src)
	{
		if (this->_array != nullptr)
			delete[] (this->_array);
		this->_size = src._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->_array[i] = src._array[i];
		}
	}
	return (*this);
}


template <typename T>
T & Array<T>::operator[](unsigned int index)
{
	return ()
}


template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}
/*
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		unsigned int	size() const;

*/