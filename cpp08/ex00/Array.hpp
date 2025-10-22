/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 00:07:47 by gorg              #+#    #+#             */
/*   Updated: 2025/10/08 00:07:47 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <algorithm>
#include <vector>
template <typename T>
typename T::iterator easyfind(T &cont, int n)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it != cont.end())
		return it;
	throw std::out_of_range("Value not found");
}

template <typename T>
typename T::const_iterator easyfind(T const &cont, int n)
{
	typename T::const_iterator it = std::find(cont.begin(), cont.end(), n);
	if (it != cont.end())
		return it;
	throw std::out_of_range("Value not found");
}