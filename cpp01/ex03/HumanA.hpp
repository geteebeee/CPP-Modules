/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:00:23 by gorg              #+#    #+#             */
/*   Updated: 2025/05/31 18:35:10 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	
	std::string	name;
	Weapon&	weapon;

public:
	HumanA(std::string name, Weapon& weapon);
	void attack() const;
};

