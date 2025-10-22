/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:04:12 by gorg              #+#    #+#             */
/*   Updated: 2025/09/28 18:45:53 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::~AForm() {}

AForm::AForm(const AForm &f) : _name(f._name), _signed(f._signed), _grade(f._grade), _req(f._req) {}

AForm::AForm(std::string const &name, int grade, int req) : _name(name), _signed(false), _grade(grade), _req(req)
{
	if (grade > 150 || req > 150)
		throw GradeTooLowException();
	if (grade < 1 || req < 1)
		throw GradeTooHighException();
}

AForm &AForm::operator=(const AForm &f) {
	if (this != &f)
	{
		_signed = f._signed;
	}
	return *this;
}

std::string const &AForm::getName() const { return _name; }
bool AForm::getSigned() const { return _signed; }
int AForm::getGrade() const { return _grade; }
int AForm::getReq() const { return _req; }

void AForm::beSigned(Bureaucrat const &b)
{
	if (this->getSigned())
		throw AlreadySignedException();
	if (b.getGrade() > _grade)
		throw GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";

}

const char *AForm::GradeTooLowException::what() const throw() 
{
	return "grade too low";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "not signed";
}


void AForm::validityCheck(Bureaucrat const &executor) const
{

	if (!_signed)
		throw NotSignedException();
	if (executor.getGrade() > _req)
		throw GradeTooLowException();
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "form is already signed";

}

std::ostream &operator<<(std::ostream &os, AForm const &f)
{
	os << std::boolalpha << "-Form-\nName: " << f.getName() << "\nGrade: " << f.getGrade() << "\nRequired grade: " << f.getReq() << "\nSigned: " << f.getSigned() << std::endl << std::noboolalpha;
	return os;
}