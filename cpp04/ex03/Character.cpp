/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:48:41 by gorg              #+#    #+#             */
/*   Updated: 2025/09/22 23:48:41 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name(""), inv{nullptr, nullptr, nullptr, nullptr} {}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete inv[i];
		inv[i] = nullptr;
	}
}
Character::Character(std::string _name) : name(_name), inv{nullptr, nullptr, nullptr, nullptr} {};

Character::Character(const Character &rhs) : name(rhs.name)
{
	for (int i = 0; i < 4; i++)
	{
		inv[i] = nullptr;
		if (rhs.inv[i] != nullptr)
			this->inv[i] = rhs.inv[i]->clone();
	}
}

Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		for (int i = 0; i < 4; i++)
		{
			delete inv[i];
			inv[i] = nullptr;
			if (rhs.inv[i] != nullptr)
				this->inv[i] = rhs.inv[i]->clone();
		}
	}
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (inv[i] == nullptr)
		{
			inv[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && inv[idx])
		inv[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && inv[idx])
		inv[idx]->use(target);
}