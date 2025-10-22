/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:43:54 by gorg              #+#    #+#             */
/*   Updated: 2025/09/29 21:43:54 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	data = "lel";
	data1 = "lel2";
}

Data::~Data() {}

Data::Data(const Data &rhs) : data(rhs.data), data1(rhs.data1) {}

Data &Data::operator=(const Data &rhs)
{
	if (this != &rhs)
	{
		data = rhs.data;
		data1 = rhs.data1;
	}
	return *this;
}