/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:47:06 by gorg              #+#    #+#             */
/*   Updated: 2025/09/05 21:50:50 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
	ScavTrap();
	ScavTrap(std::string const &name);
	~ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	void takeDamage(unsigned int amount) override;
	void attack(const std::string &target) override;
	void beRepaired(unsigned int amount) override;
	void guardGate();
};