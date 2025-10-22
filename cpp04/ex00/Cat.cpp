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

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Defaut cat constructor called." << std::endl;
}

Cat::~Cat ()
{
	std::cout << "Cat destructor called." << std::endl;
}


Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat overload operator" <<std::endl;
	if (this != &src)
		type = src.type;
	return *this;
}

void Cat::makeSound() const 
{
	std::cout << "Meow" << std::endl;
}