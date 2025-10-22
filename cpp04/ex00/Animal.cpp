/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:14:12 by gorg              #+#    #+#             */
/*   Updated: 2025/06/11 00:21:05 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Schrodinger")
{
	std::cout << "Default animal constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor animal called." << std::endl;
}

Animal::Animal(const Animal &src) : type(src.type)
{
	std::cout << "Copy constructor called." <<std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "Overload assignemnt animal called." << std::endl;
	if (this != &rhs)
		type = rhs.type;
	return *this;
}

Animal::Animal(std::string _type) : type(_type)
{
	std::cout << "Parameter constructor for animal called." <<std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Chigapugulaa" << std::endl;
}


