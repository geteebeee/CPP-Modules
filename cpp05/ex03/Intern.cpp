/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:19:18 by gorg              #+#    #+#             */
/*   Updated: 2025/09/28 18:28:49 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &) {}

Intern &Intern::operator=(Intern const &) { return *this; }

AForm *Intern::robo(std::string const &t) { return new RobotomyRequestForm(t); }

AForm *Intern::pres(std::string const &t) { return new PresidentialPardonForm(t); }

AForm *Intern::shr(std::string const &t) { return new ShrubberyCreationForm(t); }


const char *Intern::FormNotFoundException::what() const throw()
{
	return "the form was not found";
}



AForm *Intern::makeForm(std::string const &form, std::string const &target)
{
	std::string forms[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation",
	};

	AForm* (Intern::*formPtrs[3])(std::string const &t) = {
		&Intern::pres,
		&Intern::robo,
		&Intern::shr,
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creates " << forms[i] << std::endl;
			return (this->*formPtrs[i])(target);
		}
	}
	std:: cout << "Intern couldn't find the correct form probably..." << std::endl;
	throw FormNotFoundException();
	return nullptr;
}
