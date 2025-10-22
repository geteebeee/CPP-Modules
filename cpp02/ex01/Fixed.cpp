/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:20:20 by gorg              #+#    #+#             */
/*   Updated: 2025/08/16 21:11:34 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &num)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = num;
}

Fixed& Fixed::operator=(const Fixed &num)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &num)
		value = num.getRawBits();
	return *this;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	value = val << bits;
}


Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	value = static_cast<int>(roundf(f * (1 << bits)));
}


float Fixed::toFloat() const
{
	return value / static_cast<float>(1 << bits);
}

int Fixed::toInt() const
{
	return value >> bits;
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}




int Fixed::getRawBits() const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

//
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

