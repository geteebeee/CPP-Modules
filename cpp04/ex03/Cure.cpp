/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:48:47 by gorg              #+#    #+#             */
/*   Updated: 2025/09/22 23:48:47 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

Cure::Cure(const Cure &rhs) : AMateria(rhs.getType()) {}

AMateria *Cure::clone() const
{
	try
	{
		return new Cure;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return nullptr;
	}
}
	
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}