/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:48:38 by gorg              #+#    #+#             */
/*   Updated: 2025/05/25 17:37:45 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	: first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

Contact::~Contact() {}

void Contact::writer(const std::string &str) const
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void Contact::show_all() const
{
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

void Contact::summary(int index) const
{
	std::cout << "|" << std::setw(10) << index << "|";
	writer(first_name);
	std::cout << "|";
	writer(last_name);
	std::cout << "|";
	writer(nickname);
	std::cout << "|" << std::endl;
}


void Contact::add_contact()
{
	while (1)
	{
		std::cout << "Enter First Name: ";
		std::getline(std::cin, first_name);
		if (!first_name.empty())
			break ;
		std::cout << "First name can't be empty." << std::endl;
	}
	while (1)
	{
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, last_name);
		if (!last_name.empty())
			break ;
		std::cout << "Last name can't be empty." << std::endl;
	}
	while (1)
	{
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, nickname);
		if (!nickname.empty())
			break ;
		std::cout << "Nickname can't be empty." << std::endl;
	}
	while (1)
	{
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, phone_number);
		if (!phone_number.empty())
			break ;
		std::cout << "Phone number can't be empty." << std::endl;
	}
	while (1)
	{
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, darkest_secret);
		if (!darkest_secret.empty())
			break ;
		std::cout << "Darkest secret can't be empty." << std::endl;
	}
}
