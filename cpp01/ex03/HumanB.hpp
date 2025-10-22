/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:23:18 by gorg              #+#    #+#             */
/*   Updated: 2025/05/31 18:35:25 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
private:	
	std::string	name;
	Weapon* weapon;
public:
	HumanB(const std::string& name);
	void setWeapon(Weapon& newwep);
	void attack() const;

};

