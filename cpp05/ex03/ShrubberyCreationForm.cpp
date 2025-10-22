/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:07:13 by gorg              #+#    #+#             */
/*   Updated: 2025/09/28 16:13:43 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	validityCheck(executor);

	std::ofstream os(_target + "_shrubbery");
	if (!os)
		return ;

	os << R"(        ccee88oo
      C8O8O8Q8PoOb o8oo
     dOB69QO8PdUOpugoO9bD
     CgggbU8OU qOp qOdoUOdcb
       6OuU  /p u gcoUodpP
          \\\//  /douUP
            \\\////
             |||/"
             |||\/
             |||||
      .....//||||\....)"
       << "\n";
}