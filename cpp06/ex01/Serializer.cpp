/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:38:53 by gorg              #+#    #+#             */
/*   Updated: 2025/09/29 21:38:53 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

 uintptr_t Serializer::serialize(Data *ptr)
{
//	std::cout << "Serializeee!!\n";
	return reinterpret_cast<std::uintptr_t>(ptr);
}

 Data *Serializer ::deserialize(uintptr_t raw)
{
//	std::cout << "Deserializerrr!!\n";
	return reinterpret_cast<Data *>(raw);
}