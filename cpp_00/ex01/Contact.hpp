/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:23:14 by lsalmi            #+#    #+#             */
/*   Updated: 2023/12/08 18:23:16 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_secret;
	public:
		Contact(void);
		~Contact(void);
		void		setFirstName(std::string first_name);
		void		setLastName(std::string last_name);
		void		setNickname(std::string nickname);
		void		setPhoneNumber(std::string phone_number);
		void		setSecret(std::string secret);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getSecret(void);
};

#endif
