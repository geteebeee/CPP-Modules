/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:01:08 by gorg              #+#    #+#             */
/*   Updated: 2025/07/01 18:51:54 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setname(std::string newName)
{
	name = newName;
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde = nullptr;
	try
	{
		horde = new Zombie[N];
	}
	catch (const std::bad_alloc& e) 
	{
		std::cout << "Allocation failed: " << e.what() << std::endl;
		return -1;
	}
	int i = 0;

	while (i < N)
	{
		horde[i].setname(name);
		i++;
	}
	return (horde);
}