/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:35:50 by gorg              #+#    #+#             */
/*   Updated: 2025/09/28 17:59:19 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _grade;
		int const _req;
	public:
		Form() = delete;
		~Form();
		Form(const Form &f);
		Form(std::string const &name, int grade, int req); 
		Form &operator=(const Form &f);

		std::string const &getName() const;
		bool getSigned() const;
		int getGrade() const;
		int getReq() const;

		void beSigned(Bureaucrat const &b);

		class GradeTooHighException : public std::exception
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
std::ostream &operator<<(std::ostream &os, const Form &f);