/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:16:54 by gorg              #+#    #+#             */
/*   Updated: 2025/06/06 23:24:41 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private:
	const Fixed x;
	const Fixed y;

	public:
	Point();
	~Point();
	Point(const float x, const float y);
	Point(const Point &copy);
	Point &operator=(Point const &other);
	const Fixed get_x() const;
	const Fixed get_y() const;
	
};

std::ostream &operator<<(std::ostream &out, const Point &point);
bool bsp( Point const a, Point const b, Point const c, Point const point);
