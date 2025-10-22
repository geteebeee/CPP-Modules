/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:46:40 by gorg              #+#    #+#             */
/*   Updated: 2025/09/05 22:15:03 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :  ClapTrap("default"), FragTrap("default"), ScavTrap("default"), name("default")
{
	this->hp = 100;
	this->ep = 50;
	this->dmg = 30;
	std::cout << "DiamondTrap " << name << "default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &_name) : ClapTrap(_name + "_clap_name"), FragTrap(_name + "_clap_name"), ScavTrap(_name + "_clap_name"), name(_name)
{
	this->hp = 100;
	this->ep = 50;
	this->dmg = 30;
	std::cout << "DiamondTrap " << name << "parameter constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other),  FragTrap(other), ScavTrap(other), name(other.name)
{
	std::cout << "DiamondTrap " << name << " copy constructor.\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	std::cout << "DiamondTrap " << name << " copy assignment.\n";
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destructor.\n";
}

void DiamondTrap::attack(const std::string &target)
{
	if (hp == 0)
		std::cout << "DiamondTrap " << name << " has 0 hp." << std::endl;
	else if (ep > 0){
		std::cout << "DiamondTrap " << name << " attacks " << target << " causing " << dmg << " points of damage!" << std::endl;
		ep--;
	}
	else if (ep == 0)
		std::cout << "DiamondTrap " << name << " is out of energy." << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
		std::cout << "DiamondTrap " << name << " is already basically pretty dead..." << std::endl;
	else if (hp < amount)
	{
		std::cout << "DiamondTrap " << name << " takes " << hp << " damage." << std::endl;
		hp = 0;
	}
	else
	{
		std::cout << "DiamondTrap " << name << " takes " << amount << " damage." << std::endl;
		hp -= amount;
	}
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (hp == 100)
		std::cout << "DiamondTrap " << name << " is fully repaired!" << std::endl;
	else if (ep == 0)
		std::cout << "DiamondTrap " << name << " is out of energy." << std::endl;
	else if (amount + hp >= 100)
	{
		unsigned int repaired = 100 - hp;
		std::cout << "DiamondTrap " << name << " is repaired " << repaired << " points." << std::endl;
		hp += repaired;
		--ep;
	}
	else
	{
		std::cout << "DiamondTrap " << name << " is repaired " << amount << " points." << std::endl;
		hp += amount;
		--ep;
	}
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << " | ClapTrap name: " << ClapTrap::get_name() << "\n";
}