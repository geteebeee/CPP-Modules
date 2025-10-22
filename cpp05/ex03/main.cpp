// #include "Bureaucrat.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include <iostream>
// #include "Intern.hpp"

// int main()
// {
// 	try
// 	{
// 		Bureaucrat weak("One", 150);
// 		Bureaucrat mid("Two", 45);
// 		Bureaucrat strong("Tri", 1);

// 		ShrubberyCreationForm shrub("Shr");
// 		RobotomyRequestForm   robo("rob");
// 		PresidentialPardonForm pardon("pre");

// 		std::cout << shrub << "\n" << robo << "\n" << pardon << "\n\n";
// 		// ShrubberyCreationForm: Required grades: sign 145, exec 137

// 		// •RobotomyRequestForm: Required grades: sign 72, exec 45

// 		// •PresidentialPardonForm: Required grades: sign 25, exec 5

// 		Intern man;
// 		AForm *asd = man.makeForm("shrubbery ", "many");
// 		delete asd;

// 	}
// 	catch (const std::exception& e) {
// 		std::cout << "Exception: " << e.what() << "\n";
// 	}
// 	return 0;
// }

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <memory>

int main ()
{
	Intern i1;
	Bureaucrat b1("Prezes", 1);
	Bureaucrat b2("normik", 150);
	{
		std::cout << "--test one--" << std::endl;
		try{
			AForm *test = i1.makeForm("bye", "test");
			b2.signForm(*test);
			b2.executeForm(*test);
			b1.signForm(*test);
			b1.executeForm(*test);
			delete test;
		}
		catch (std::exception &e){
			std::cout << "couldn't execute because " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "--test two--" << std::endl;
		try{
			AForm *form = i1.makeForm("presidential pardon", "Luigi");
			b1.signForm(*form);
			b1.executeForm(*form);
			delete form;
		}
		catch (std::exception &e){
			std::cout << "couldn't execute because " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "--test three--" << std::endl;
		try{
			AForm *what = i1.makeForm("robotomy request", "here");
			b1.signForm(*what);
			b2.executeForm(*what);
			delete what;
		}
		catch(std::exception &e){
			std::cout << "couldn't execute because " << e.what() << std::endl;
		}
	}
		std::cout << std::endl << "--one more--" << std::endl;
		try {
			AForm *problem = i1.makeForm("da fcuk is this", "STH");
			b2.signForm(*problem);
			b2.executeForm(*problem);
			delete problem;
		} 
		catch (const std::exception &e) {
			std::cout << "couldn't execute because of " << e.what() << std::endl;
		}
	return 0;
}