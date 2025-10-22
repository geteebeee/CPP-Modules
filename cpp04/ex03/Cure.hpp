/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:48:50 by gorg              #+#    #+#             */
/*   Updated: 2025/09/22 23:48:50 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>
class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure &operator=(const Cure &rhs);
		Cure(const Cure &rhs);

		AMateria* clone() const override;
		void use(ICharacter& target) override;
};