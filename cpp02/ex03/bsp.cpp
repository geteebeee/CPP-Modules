/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:17:18 by gorg              #+#    #+#             */
/*   Updated: 2025/06/06 13:10:16 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float calculate(Point const a, Point const b, Point const point)
{
		float x1 = a.get_x().toFloat();
		float y1 = a.get_y().toFloat();
		float x2 = b.get_x().toFloat();
		float y2 = b.get_y().toFloat();
		float px = point.get_x().toFloat();
		float py = point.get_y().toFloat();
		
		float ret = (x2-x1) * (py-y1) - (y2 - y1) * (px - x1);
		return ret;
		
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float ab = calculate(a, b, point);
	float ac = calculate(c, a, point);
	float bc = calculate(b, c, point);
	std::cout << ab << ","<< ac << "," << bc<< std::endl;
	return((ab > 0 && ac > 0 && bc > 0) || (ab < 0 && ac < 0 && bc < 0 ));
}