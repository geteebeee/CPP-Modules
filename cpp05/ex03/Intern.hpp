/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:08:56 by gorg              #+#    #+#             */
/*   Updated: 2025/09/28 18:24:51 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const &);
		Intern &operator=(Intern const &);
		AForm *makeForm(std::string const &form, std::string const &target);
		AForm *robo(std::string const &t);
		AForm *shr(std::string const &t);
		AForm *pres(std::string const &t);

		class FormNotFoundException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};