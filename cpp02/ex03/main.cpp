/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:22:11 by gorg              #+#    #+#             */
/*   Updated: 2025/06/06 23:24:17 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(0.0f, 5.0f);
	Point point(1.0f, 1.0f);

	bool ret = bsp(a,b,c,point);
	std::cout << (ret ? "true" : "false") << std::endl;
	return 0;
}

