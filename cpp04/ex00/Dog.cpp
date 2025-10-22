/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:25:06 by gorg              #+#    #+#             */
/*   Updated: 2025/09/26 19:57:16 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called." << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog copy constructor" <<std::endl;
}


Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog overload constructor" << std::endl;
	if (this != &src)
		type = src.type;
	return *this;
}



void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}

