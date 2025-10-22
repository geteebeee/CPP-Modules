/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 01:15:50 by gorg              #+#    #+#             */
/*   Updated: 2025/09/05 21:56:29 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Maybe no?
FragTrap::FragTrap() : ClapTrap()
{
	this->hp = 100;
	this->ep = 100;
	this->dmg = 30;
	std::cout << "FragTrap " << name << " constuctored." << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 100;
	this->dmg = 30;
	std::cout << "FragTrap " << name << " constuctored." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructoreded." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy construcor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap copy assigment called" <<std::endl;
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (hp == 0)
		std::cout << "FragTrap " << name << " has 0 hp." << std::endl;
	else if (ep > 0){
		std::cout << "FragTrap " << name << " attacks " << target << " causing " << dmg << " points of damage!" << std::endl;
		ep--;
	}
	else if (ep == 0)
		std::cout << "FragTrap " << name << " is out of energy." << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
		std::cout << "FragTrap " << name << " is already basically pretty dead..." << std::endl;
	else if (hp < amount)
	{
		std::cout << "FragTrap " << name << " takes " << hp << " damage." << std::endl;
		hp = 0;
	}
	else
	{
		std::cout << "FragTrap " << name << " takes " << amount << " damage." << std::endl;
		hp -= amount;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (hp == 100)
		std::cout << "FragTrap " << name << " is fully repaired!" << std::endl;
	else if (ep == 0)
		std::cout << "FragTrap " << name << " is out of energy." << std::endl;
	else if (amount + hp >= 100)
	{
		unsigned int repaired = 100 - hp;
		std::cout << "FragTrap " << name << " is repaired " << repaired << " points." << std::endl;
		hp += repaired;
		--ep;
	}
	else
	{
		std::cout << "FragTrap " << name << " is repaired " << amount << " points." << std::endl;
		hp += amount;
		--ep;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests the highest of fives." << std::endl;
}