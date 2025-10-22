/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:55:20 by gorg              #+#    #+#             */
/*   Updated: 2025/10/03 19:55:20 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void iter(T *arr, unsigned int len, void(*func)(T &))
{
	for(unsigned int i = 0; i < len; i++)
	{
		(func)(arr[i]);
	}
}

template <typename T>
void iter(T const *arr, unsigned int len, void(*func)(T const &))
{
	for(unsigned int i = 0; i < len; i++)
	{
		(func)(arr[i]);
	}
}
