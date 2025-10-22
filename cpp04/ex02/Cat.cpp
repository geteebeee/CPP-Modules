/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:32:55 by gorg              #+#    #+#             */
/*   Updated: 2025/06/12 00:12:13 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called." << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src), brain(new Brain(*src.brain))
{
	std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat& src)
{
	std::cout << "Cat assignment operator called." << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		Brain* nb = new Brain(*src.brain);
		delete brain;
		brain = nb;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

void Cat::setIdea(int n, const std::string& idea)
{
	brain->setIdea(n, idea);
}

std::string Cat::getIdea(int n) const
{
	return brain->getIdea(n);
}