/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:04:12 by gorg              #+#    #+#             */
/*   Updated: 2025/09/28 17:59:48 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form() {}

Form::Form(const Form &f) : _name(f._name), _signed(f._signed), _grade(f._grade), _req(f._req) {}

Form::Form(std::string const &name, int grade, int req) : _name(name), _signed(false), _grade(grade), _req(req)
{
	if (grade > 150 || req > 150)
		throw GradeTooLowException();
	if (grade < 1 || req < 1)
		throw GradeTooHighException();
}

Form &Form::operator=(const Form &f) {
	if (this != &f)
	{
		_signed = f._signed;
	}
	return *this;
}

std::string const &Form::getName() const { return _name; }
bool Form::getSigned() const { return _signed; }
int Form::getGrade() const { return _grade; }
int Form::getReq() const { return _req; }

void Form::beSigned(Bureaucrat const &b)
{
	if (this->getSigned())
		throw AlreadySignedException();
	if (b.getGrade() > _grade)
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";

}

const char *Form::AlreadySignedException::what() const throw()
{
	return "form is already signed";

}

const char *Form::GradeTooLowException::what() const throw() 
{
	return "grade too low";
}


std::ostream &operator<<(std::ostream &os, Form const &f)
{
	os << std::boolalpha << "-Form-\nName: " << f.getName() << "\nGrade: " << f.getGrade() << "\nRequired grade: " << f.getReq() << "\nSigned: " << f.getSigned() << std::endl << std::noboolalpha;
	return os;
}