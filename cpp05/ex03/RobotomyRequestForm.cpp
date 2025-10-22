/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:08:08 by gorg              #+#    #+#             */
/*   Updated: 2025/09/28 16:13:17 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	validityCheck(executor);
	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n";
	if (rand() % 2)
		std::cout << _target << " has been robotomized\n";
	else
		std::cout << _target << "'s robotomization has failed\n";
}