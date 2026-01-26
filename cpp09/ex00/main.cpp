/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:23:47 by gorg              #+#    #+#             */
/*   Updated: 2025/10/09 20:26:45 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Wrong input format ( ./btc \"inputfile\".txt )" << std::endl;
	else
	{
		std::string filename(av[1]);
		BitcoinExchange b(filename);
	}
	return 0;
}