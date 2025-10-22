/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:36:23 by gorg              #+#    #+#             */
/*   Updated: 2025/09/29 21:36:23 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Data
{
	public:
		Data();
		~Data();
		Data(const Data &rhs);
		Data &operator=(const Data &rhs);

		std::string data;
		std::string data1;
};