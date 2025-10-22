/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:17:11 by gorg              #+#    #+#             */
/*   Updated: 2025/06/06 16:32:53 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float _x, const float _y) : x(Fixed(_x)), y(Fixed(_y)) {}

Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}

Point::~Point() {}


const Fixed Point::get_x() const
{
	return x;
}

const Fixed Point::get_y() const
{
	return y;
}

std::ostream &operator<<(std::ostream &out, const Point &point);