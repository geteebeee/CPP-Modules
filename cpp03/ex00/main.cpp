/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:12:52 by gorg              #+#    #+#             */
/*   Updated: 2025/09/05 21:38:07 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.takeDamage(3);
	b.beRepaired(2);

	for (int i = 0; i < 11; ++i)
		a.attack("B");
	b.takeDamage(20);
	b.attack("A");
	b.beRepaired(1);

	return 0;
}