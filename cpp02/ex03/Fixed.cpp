/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:20:20 by gorg              #+#    #+#             */
/*   Updated: 2025/06/03 18:14:13 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"


Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	value = val << bits;
}


Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(val * (1 << bits));
}


Fixed::Fixed(const Fixed &num)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = num;
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

float Fixed::toFloat() const
{
	return (float)value / (1 << bits);
}

int Fixed::toInt() const
{
	return (int)value >> bits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
Fixed& Fixed::operator=(const Fixed &num)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &num)
		value = num.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &num) const
{
	return value > num.value;
}

bool Fixed::operator<(const Fixed &num) const
{
	return value < num.value;
}

bool Fixed::operator>=(const Fixed &num) const
{
	return value >= num.value;
}

bool Fixed::operator<=(const Fixed &num) const
{
	return value <= num.value;
}

bool Fixed::operator==(const Fixed &num) const
{
	return value == num.value;
}

bool Fixed::operator!=(const Fixed &num) const
{
	return value != num.value;
}


Fixed Fixed::operator+(const Fixed &num) const
{
	return Fixed(this->toFloat() + num.toFloat());
}

Fixed Fixed::operator-(const Fixed &num) const
{
	return Fixed(this->toFloat() - num.toFloat());
}

Fixed Fixed::operator*(const Fixed &num) const
{
	return Fixed(this->toFloat() * num.toFloat());
}

Fixed Fixed::operator/(const Fixed &num) const
{
	return Fixed(this->toFloat() / num.toFloat());
}

Fixed& Fixed::operator++()
{
	value++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	value++;
	return temp;
}

Fixed& Fixed::operator--()
{
	value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	value--;
	return temp;
}


Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

