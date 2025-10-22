/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:50:16 by gorg              #+#    #+#             */
/*   Updated: 2025/09/05 21:40:11 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Bober"), hp(10), ep(10), dmg(0)
{
	std::cout << "Default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string _nm) : name(_nm), hp(10), ep(10), dmg(0)
{
	std::cout << "Parameter consturctor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : name(src.name), hp(src.hp), ep(src.ep), dmg(src.dmg)
{
	std::cout << "Copy constructor" << std::endl;
}


ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "Overload Assignment" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hp = rhs.hp;
		this->ep = rhs.ep;
		this->dmg = rhs.dmg;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor!" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
	if (hp == 0)
		std::cout << "ClapTrap " << name << " has 0 hp." << std::endl;
	else if (ep == 0)
		std::cout << "ClapTrap " << name << " is out of energy." << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " << dmg << " points of damage!" << std::endl;
		ep--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
		std::cout << "ClapTrap " << name << " is already basically pretty dead..." << std::endl;
	else if (hp < amount)
	{
		std::cout << "ClapTrap " << name << " takes " << hp << " damage." << std::endl;
		hp = 0;
	}
	else
	{
		std::cout << "ClapTrap " << name << " takes " << amount << " damage." << std::endl;
		hp -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hp == 10)
		std::cout << "ClapTrap " << name << " is fully repaired!" << std::endl;
	else if (ep == 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy." << std::endl;
	}
	else if (amount + hp >= 10)
	{
		unsigned int repaired = 10 - hp;
		std::cout << "ClapTrap " << name << " is repaired " << repaired << " points." << std::endl;
		hp += repaired;
		ep--;
	}
	else
	{
		std::cout << "ClapTrap " << name << " is repaired " << amount << " points." << std::endl;
		hp += amount;
		ep--;
	}
}

unsigned int	ClapTrap::get_ep()
{
	return ep;
}

unsigned int	ClapTrap::get_hp()
{
	return hp;
}

unsigned int	ClapTrap::get_dmg()
{
	return dmg;
}

std::string	ClapTrap::get_name()
{
	return name;
}

