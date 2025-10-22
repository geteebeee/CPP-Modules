/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:12:52 by gorg              #+#    #+#             */
/*   Updated: 2025/09/05 21:55:38 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap d("Diamond");

	d.whoAmI();
	d.attack("target");
	d.takeDamage(42);
	d.beRepaired(10);

	for (int i = 0; i < 60; ++i) 
		d.attack("bot");
	d.whoAmI();


	d.takeDamage(1000);
	d.attack("ghost");
	return 0;

}
