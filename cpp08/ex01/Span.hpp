/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:45:23 by gorg              #+#    #+#             */
/*   Updated: 2025/10/08 22:45:23 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>
#include <stdexcept>
#include <limits.h>
#include <algorithm>

class Span
{
	private:
		std::multiset<int> _numbers;
		unsigned int _maxSize;
	public:
		Span() = delete;
		~Span();
		Span(unsigned int N);
		Span(Span const &other);
		Span &operator=(Span const &rhs);

		unsigned int shortestSpan();
		unsigned int longestSpan();
		void addNumber(int add);
		
template <typename T>
void addNumber(T first, T last)
{
	for (; first != last; first++)
		addNumber(*first);	
}

};
