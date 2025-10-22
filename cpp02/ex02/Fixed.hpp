/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:20:11 by gorg              #+#    #+#             */
/*   Updated: 2025/06/03 16:32:57 by gorg             ###   ########.fr       */
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


bool operator>(const Fixed &num) const;
bool operator<(const Fixed &num) const;
bool operator>=(const Fixed &num) const;
bool operator<=(const Fixed &num) const;
bool operator==(const Fixed &num) const;
bool operator!=(const Fixed &num) const;

Fixed operator+(const Fixed &num) const;
Fixed operator-(const Fixed &num) const;
Fixed operator*(const Fixed &num) const;
Fixed operator/(const Fixed &num) const;

Fixed& operator++();
Fixed operator++(int);
Fixed& operator--();
Fixed operator--(int);

static Fixed& min(Fixed& a, Fixed& b);
static const Fixed& min(const Fixed& a, const Fixed& b);
static Fixed& max(Fixed& a, Fixed& b);
static const Fixed& max(const Fixed& a, const Fixed& b);

};
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

