/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 21:59:00 by gorg              #+#    #+#             */
/*   Updated: 2025/09/24 21:59:00 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : type{nullptr, nullptr, nullptr, nullptr} {}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete type[i];
		type[i] = nullptr;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			delete type[i];
			type[i] = nullptr;
			if (rhs.type[i] != nullptr)
				this->type[i] = rhs.type[i]->clone();
		}
	}
	return *this;
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
	for (int i = 0; i < 4; i++)
	{
		type[i] = nullptr;
		if (rhs.type[i] != nullptr)
			this->type[i] = rhs.type[i]->clone();
	}
}

void MateriaSource::learnMateria(AMateria* target)
{
	if (!target)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!type[i])
		{
			type[i] = target;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &target)
{
	for (int i = 0; i < 4; i++)
	{
		if (type[i] && type[i]->getType() == target)
			return type[i]->clone();
	}
	return 0;
}
