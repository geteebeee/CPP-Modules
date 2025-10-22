/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:12:17 by gorg              #+#    #+#             */
/*   Updated: 2025/07/01 18:57:54 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl men;

	men.complain("DEBUG");
	men.complain("asd");
	men.complain("INFO");
	men.complain("WARNING");
	men.complain("ERROR");
	men.complain("debug");
	return (0);
}