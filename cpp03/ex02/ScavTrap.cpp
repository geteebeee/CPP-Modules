/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:51:37 by gorg              #+#    #+#             */
/*   Updated: 2025/09/05 21:50:34 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hp = 100;
	this->ep = 50;
	this->dmg = 20;
	std::cout << "ScavTrap " << name << " constuctored." << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 50;
	this->dmg = 20;
	std::cout << "ScavTrap " << name << " constuctored." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructoreded." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy construcor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assigment called" <<std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (hp == 0)
		std::cout << "ScavTrap " << name << " has 0 hp." << std::endl;
	else if (ep > 0){
		std::cout << "ScavTrap " << name << " attacks " << target << " causing " << dmg << " points of damage!" << std::endl;
		ep--;
	}
	else if (ep == 0)
		std::cout << "ScavTrap " << name << " is out of energy." << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
		std::cout << "ScavTrap " << name << " is already basically pretty dead..." << std::endl;
	else if (hp < amount)
	{
		std::cout << "ScavTrap " << name << " takes " << hp << " damage." << std::endl;
		hp = 0;
	}
	else
	{
		std::cout << "ScavTrap " << name << " takes " << amount << " damage." << std::endl;
		hp -= amount;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (hp == 100)
		std::cout << "ScavTrap " << name << " is fully repaired!" << std::endl;
	else if (ep == 0)
		std::cout << "ScavTrap " << name << " is out of energy." << std::endl;
	else if (amount + hp >= 100)
	{
		unsigned int repaired = 100 - hp;
		std::cout << "ScavTrap " << name << " is repaired " << repaired << " points." << std::endl;
		hp += repaired;
		--ep;
	}
	else
	{
		std::cout << "ScavTrap " << name << " is repaired " << amount << " points." << std::endl;
		hp += amount;
		--ep;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}