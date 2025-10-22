/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:32:50 by gorg              #+#    #+#             */
/*   Updated: 2025/05/22 21:22:18 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void writer(const std::string& str)
{
	for (char c : str)
		std::cout << (char)std::toupper((c));
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac >= 2)
	{
		while (av[i])
		{
			writer(av[i]);
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}