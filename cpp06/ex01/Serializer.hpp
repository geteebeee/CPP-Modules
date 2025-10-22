/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:33:01 by gorg              #+#    #+#             */
/*   Updated: 2025/09/29 21:33:01 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <cstdint>
#include <iostream>

class Serializer
{
	public:
		Serializer() = delete;
		~Serializer() = delete;
		Serializer(const Serializer &) = delete;
		Serializer &operator=(const Serializer &) = delete;

		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};