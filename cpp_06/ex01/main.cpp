/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:53:28 by lsalmi            #+#    #+#             */
/*   Updated: 2024/03/20 16:53:30 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	std::cout << "\n" << CYAN << "Creating data..." << COLRESET << std::endl;
	Data data;

	data.str = "I like unicorns";
	data.n = 123;

	std::cout << "Data address: " << &data << std::endl;
	std::cout << "Data string: " << data.str << std::endl;
	std::cout << "Data number: " << data.n << std::endl;

	std::cout << "\n" << MAG << "Serializing to uintptr_t ..." << COLRESET << std::endl;
	uintptr_t ptr = Serializer::serialize(&data);

	std::cout << "Serialized uintptr_t: " << ptr << COLRESET << std::endl;

	std::cout << "\n" << MAG << "Deserializing back to Data pointer ..." << COLRESET << std::endl;
	Data *deserialized = Serializer::deserialize(ptr);

	std::cout << "Deserialized data string: " << deserialized->str << std::endl;
	std::cout << "Deserialized number: " << deserialized->n << std::endl;
}
