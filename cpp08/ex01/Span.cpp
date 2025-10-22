/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 23:09:24 by gorg              #+#    #+#             */
/*   Updated: 2025/10/08 23:09:24 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::~Span() {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(Span const &other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_maxSize = rhs._maxSize;
		_numbers = rhs._numbers;
	}
	return *this;
}
#include <iostream>
unsigned int Span::shortestSpan()
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Span has 0 or 1 elements");
	long long diff = UINT_MAX;
	long long current = LONG_MIN;
	//auto test = _numbers.begin();
	for (long long i : _numbers)
	{
		if (current == i)
			continue ;
		// if (static_cast<long long>(*test) == i)
		// 	;
		// else
		// 	std::swap(i, current);
		if (diff == 0)
			return 0;
		//std::cout << "------COM" << current << " "<< i << " VS" <<  " " << diff <<std::endl;
		long long vs = i - current;
		//std::cout << "COM" << current << " "<< i << " VS" <<vs << " " << diff <<std::endl;
		if (vs < diff && vs >= 0)
			diff = vs;
		current = i;
	}
	return diff;
}

unsigned int Span::longestSpan()
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Span has 0 or 1 elements");
	auto start = _numbers.begin();
	auto end = _numbers.end();
	end--;
	auto val1 = static_cast<long>(*start);
	auto val2 = static_cast<long>(*end);
	return val2-val1;
}

void Span::addNumber(int add)
{
	if (_maxSize == _numbers.size())
		throw std::runtime_error("Span is full");
	_numbers.insert(add);
}