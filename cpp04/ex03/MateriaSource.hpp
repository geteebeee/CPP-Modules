/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:52:47 by gorg              #+#    #+#             */
/*   Updated: 2025/09/22 23:52:47 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;
class MateriaSource : public IMateriaSource
{
	private:
		AMateria *type[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &rhs);
		MateriaSource(const MateriaSource &rhs);
		
		void learnMateria(AMateria*target) override;
		AMateria* createMateria(std::string const &target) override;

};