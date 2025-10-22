/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:43:57 by gorg              #+#    #+#             */
/*   Updated: 2025/10/06 18:43:57 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *_arr;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(Array const &rhs);
		Array &operator=(Array const &rhs);

		T &operator[](unsigned int n);
		T const &operator[](unsigned int n) const;
		unsigned int size() const;
};

#include "Array.tpp"
