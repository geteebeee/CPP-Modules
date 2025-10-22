/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:48:54 by gorg              #+#    #+#             */
/*   Updated: 2025/09/22 23:48:54 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>
#include <new>
class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice &operator=(const Ice &rhs);
		Ice (const Ice &rhs);

		AMateria* clone() const;
		void use(ICharacter& target);
};