/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:45:11 by gorg              #+#    #+#             */
/*   Updated: 2025/09/26 19:57:56 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain assignment operator called." << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = src.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

std::string Brain::getIdea(int n) const
{
	if (n < 0 || n >= 100)
		return std::string();
	return ideas[n];
}

void Brain::setIdea(int n, const std::string& idea)
{
	if (n < 0 || n >= 100)
		return std::string();
	ideas[n] = idea;
}
