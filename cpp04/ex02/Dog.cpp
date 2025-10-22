/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:25:06 by gorg              #+#    #+#             */
/*   Updated: 2025/06/12 00:15:40 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog deconstructor called." << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src), brain(new Brain(*src.brain))
{
	std::cout << "Dog copy constructor" << std::endl;
}


Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog overload constructor" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		Brain* nb = new Brain(*src.brain);
		delete brain;
		brain = nb;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}

void Dog::setIdea(int n, const std::string& idea)
{
	brain->setIdea(n, idea);
}

std::string Dog::getIdea(int n) const
{
	return brain->getIdea(n);
}