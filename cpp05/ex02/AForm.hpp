/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:35:50 by gorg              #+#    #+#             */
/*   Updated: 2025/09/28 18:45:04 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		int const _grade;
		int const _req;
	public:
		AForm() = delete;
		~AForm();
		AForm(const AForm &f);
		AForm(std::string const &name, int grade, int req); 
		AForm &operator=(const AForm &f);

		std::string const &getName() const;
		bool getSigned() const;
		int getGrade() const;
		int getReq() const;

		void beSigned(Bureaucrat const &b);

		virtual void execute(Bureaucrat const & executor) const = 0;
		void validityCheck(Bureaucrat const &executor) const;


		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class AlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
std::ostream &operator<<(std::ostream &os, const AForm &f);