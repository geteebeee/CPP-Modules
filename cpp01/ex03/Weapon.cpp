/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:17:47 by gorg              #+#    #+#             */
/*   Updated: 2025/02/23 22:17:47 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string init)
	: type(init) {}

const std::string& Weapon::getType() const
{
	return (type);
}

void Weapon::setType( std::string newtype)
{
	type = newtype;
}
