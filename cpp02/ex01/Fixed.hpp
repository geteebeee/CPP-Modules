/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:20:11 by gorg              #+#    #+#             */
/*   Updated: 2025/08/16 21:05:54 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <cmath>


class Fixed
{
	private:
		int	value;
		static const int	bits = 8;

	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed &num);
		~Fixed();

		Fixed& operator=(const Fixed &num);

		float toFloat() const;
		int toInt() const;

		int getRawBits() const;
		void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

