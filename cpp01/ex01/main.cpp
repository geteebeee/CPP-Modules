/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:09:22 by gorg              #+#    #+#             */
/*   Updated: 2025/02/23 19:09:22 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "horde");
	int i = 0;
	while (i < N)
	{
		horde[i++].announce();
	}
	delete[] horde;
	return (0);
}
