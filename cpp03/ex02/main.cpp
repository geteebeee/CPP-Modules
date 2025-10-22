/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:12:52 by gorg              #+#    #+#             */
/*   Updated: 2025/09/05 21:50:19 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap f("FR4G");
	ClapTrap c("CL4P");

	f.highFivesGuys();
	f.attack("CL4P");
	c.takeDamage(5);
	c.beRepaired(3);


	f.takeDamage(40);
	f.beRepaired(20);


	for (int i = 0; i < 110; ++i)
		f.attack("dummy");
	f.attack("anyone");
	return 0;
}
