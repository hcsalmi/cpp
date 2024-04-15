/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:30:13 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/26 18:30:15 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

class Awesome
{
	public:
		Awesome(void) : _n(42) { return; }
		int get(void) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream &o, Awesome const &rhs )
{
  o << rhs.get();
  return o;
}

int main(void)
{
	std::cout << "\n\e[0;36m" << "Testing with int array: " << "\e[0m\n" << std::endl;
	Array<int> int_arr(40);
	std::cout << "Value at a random index in range: " << int_arr[2] << std::endl;
	for (int i = 0; i < 40; i++)
		int_arr[i] = i;
	std::cout << "Int array size is: " << int_arr.size() << std::endl;
	std::cout << "Index 0: \e[0;32m" << int_arr[0] << "\e[0m" << std::endl;
	std::cout << "Index 11: \e[0;32m" << int_arr[11] << "\e[0m" << std::endl;
	std::cout << "Index 19: \e[0;32m" << int_arr[19] << "\e[0m" << std::endl;
	std::cout << "Test with invalid index 66" << std::endl;
	try
	{
		std::cout << int_arr[66] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;


	std::cout << "\n\e[0;36m" << "Testing with string array: " << "\e[0m\n" << std::endl;
	Array<std::string> str_arr(20);
	for (int j = 0; j < 20; j++)
	{
		str_arr[j] = std::string("I'm index " + std::to_string(j));
	}
	std::cout << "Array size is: " << str_arr.size() << std::endl;
	std::cout << "Index 0: \e[0;32m" << str_arr[0] << "\e[0m" << std::endl;
	std::cout << "Index 11: \e[0;32m" << str_arr[11] << "\e[0m" << std::endl;
	std::cout << "Index 19: \e[0;32m" << str_arr[19] << "\e[0m" << std::endl;
	std::cout << "Test with invalid index 22" << std::endl;
	try
	{
		std::cout << str_arr[22] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;


	std::cout << "\n\e[0;36m" << "Testing with Awesome: " << "\e[0m\n" << std::endl;
	Array<Awesome> aw_arr(20);

	std::cout << "Awesome size is: " << aw_arr.size() << std::endl;

	std::cout << "Index 0: \e[0;32m" << aw_arr[0] << "\e[0m" << std::endl;
	std::cout << "Index 11: \e[0;32m" << aw_arr[11] << "\e[0m" << std::endl;
	std::cout << "Index 19: \e[0;32m" << aw_arr[19] << "\e[0m" << std::endl;

	std::cout << "Test with invalid index 22" << std::endl;
	try
	{
		std::cout << aw_arr[22] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;


	std::cout << "\n\e[0;36m" << "Testing copy constructor and assignment operator" << "\n\e[0m" << std::endl;
	Array<std::string> cpy_arr(str_arr);
	Array<std::string> def_arr;
	def_arr = str_arr;
	std::cout << std::endl;
	std::cout << "str_arr index 5: \e[0;32m" << str_arr[5] << "\e[0m" << std::endl;
	std::cout << "def_arr index 5: \e[0;32m" << def_arr[5] << "\e[0m" << std::endl;
	std::cout << "cpy_arr index 5: \e[0;32m" << cpy_arr[5] << "\e[0m" << std::endl;
	
	std::cout << "\nChanging the original array (str_arr) ...\n" << std::endl;
	str_arr[5] = "New string here";

	std::cout << "str_arr index 5: \e[0;32m" << str_arr[5] << "\e[0m" << std::endl;
	std::cout << "def_arr index 5: \e[0;32m" << def_arr[5] << "\e[0m" << std::endl;
	std::cout << "cpy_arr index 5: \e[0;32m" << cpy_arr[5] << "\e[0m" << std::endl;
	std::cout << std::endl;

	std::cout << "str_arr index 2: \e[0;32m" << str_arr[2] << "\e[0m" << std::endl;
	std::cout << "def_arr index 2: \e[0;32m" << def_arr[2] << "\e[0m" << std::endl;
	std::cout << "cpy_arr index 2: \e[0;32m" << cpy_arr[2] << "\e[0m" << std::endl;
	std::cout << std::endl;

	std::cout << "Changing default and copy arrays (def_arr and cpy_arr) ...\n" << std::endl;
	def_arr[2] = "New string here";
	cpy_arr[2] = "New string here";

	std::cout << "str_arr index 2: \e[0;32m" << str_arr[2] << "\e[0m" << std::endl;
	std::cout << "def_arr index 2: \e[0;32m" << def_arr[2] << "\e[0m" << std::endl;
	std::cout << "cpy_arr index 2: \e[0;32m" << cpy_arr[2] << "\e[0m" << std::endl;
	std::cout << std::endl;

	std::cout << "--------------------------------" << std::endl;


	return (0);
}

