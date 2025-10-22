/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:13:59 by gorg              #+#    #+#             */
/*   Updated: 2025/09/23 23:13:59 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria() : type("") {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

AMateria::AMateria(const AMateria &rhs) : type(rhs.type) {}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

