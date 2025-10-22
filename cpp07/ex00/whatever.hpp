/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:19:40 by gorg              #+#    #+#             */
/*   Updated: 2025/10/06 18:19:40 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


template <class T>
void  swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}


template <class T>
T const &min(T const &a, T const &b)
{
	return (b < a) ? b : a;
}

template <class T>
T const &max(T const &a, T const &b) 
{
	return (a < b) ? b : a;
}
