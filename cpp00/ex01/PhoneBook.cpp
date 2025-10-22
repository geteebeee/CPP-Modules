/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:16:45 by gorg              #+#    #+#             */
/*   Updated: 2025/05/25 16:35:50 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), oldest(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::add()
{
	if (count < 8)
		contacts[count++].add_contact();
	else
	{
		std::cout << "Phonebook full, overwriting oldest contact" << std::endl;
		contacts[oldest].add_contact();
		oldest = (oldest + 1) % 8;
	}
}

void PhoneBook::search() const
{
	std::string	input;
	int			index;

	if (count == 0)
	{
		std::cout << "No contacts" << std::endl;
		return;
	}
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < count; ++i)
		contacts[i].summary(i + 1);

	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (input.length() != 1 || input[0] < '1' || input[0] > ('0' + count))
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	index = input[0] - '1';
	contacts[index].show_all();
}

void PhoneBook::exit() const
{
	std::cout << "Bye" << std::endl;
}

