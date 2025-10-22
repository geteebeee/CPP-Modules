/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:48:52 by gorg              #+#    #+#             */
/*   Updated: 2025/09/22 23:48:52 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

Ice::Ice(const Ice &rhs) : AMateria(rhs.getType()) {}

AMateria *Ice::clone() const
{
	try
	{
		return new Ice;
	}
	catch (std::bad_alloc &e)
	{
		return nullptr;
	}
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}