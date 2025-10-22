/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:48:18 by gorg              #+#    #+#             */
/*   Updated: 2025/06/07 18:55:22 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
	private:
	std::string name;
	unsigned int	hp;
	unsigned int	ep;
	unsigned int dmg;
	
	public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(std::string _nm);
	ClapTrap(const ClapTrap &src);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap &operator=(const ClapTrap &rhs);

	unsigned int	get_ep();
	unsigned int	get_hp();
	std::string		get_name();
	unsigned int 	get_dmg();
};