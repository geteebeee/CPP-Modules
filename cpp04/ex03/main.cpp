/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:50:35 by gorg              #+#    #+#             */
/*   Updated: 2025/09/26 20:07:03 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <new>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

int main()
{
    // Character alice("Alice");
    // Character bob("Bob");

    // alice.equip(new Ice());
    // alice.equip(new Cure());
    // alice.equip(new Ice());
    // alice.equip(new Cure());

    // alice.equip(new Ice());

    // alice.use(0, bob); 
    // alice.use(1, bob); 
    // alice.use(4, bob); 


    // Character copy = alice;
    // alice.unequip(0); 
    // copy.use(0, bob);


    // Character charlie("Charlie");
    // charlie = alice;
    // charlie.use(1, bob);

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	delete bob;
	delete me;
	delete tmp;
	delete src;
	return 0;
}
