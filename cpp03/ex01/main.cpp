/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:12:52 by gorg              #+#    #+#             */
/*   Updated: 2025/09/05 21:41:19 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap c("CL4P");
	ScavTrap s("SC4V");

	c.attack("SC4V");
	s.takeDamage(2);
	s.beRepaired(1);

	s.attack("CL4P");
	s.guardGate();

	for (int i = 0; i < 55; ++i)
		s.attack("dummy");
	s.attack("nobody");

	s.takeDamage(150);
	s.attack("anyone");
	return 0;
}
