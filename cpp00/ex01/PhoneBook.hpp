/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:14:56 by gorg              #+#    #+#             */
/*   Updated: 2025/05/25 16:04:03 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int	count;
	int oldest;

public:
	PhoneBook();
	~PhoneBook();
	void add();
	void search() const;
	void exit() const;
};


