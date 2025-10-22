#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat weak("One", 150);
		Bureaucrat mid("Two", 45);
		Bureaucrat strong("Tri", 1);

		ShrubberyCreationForm shrub("Shr");
		RobotomyRequestForm   robo("rob");
		PresidentialPardonForm pardon("pre");

		std::cout << shrub << "\n" << robo << "\n" << pardon << "\n\n";
		// ShrubberyCreationForm: Required grades: sign 145, exec 137

		// •RobotomyRequestForm: Required grades: sign 72, exec 45

		// •PresidentialPardonForm: Required grades: sign 25, exec 5

		weak.signForm(shrub);
		mid.signForm(shrub);
		weak.executeForm(shrub);
		mid.executeForm(shrub);
		std::cout << "\n";
		std::cout << shrub << "\n\n";

		weak.signForm(robo);
		mid.signForm(robo);
		weak.executeForm(robo);
		mid.executeForm(robo);
		std::cout << "\n";

		std::cout << robo << "\n\n";

		mid.signForm(pardon);
		strong.signForm(pardon);
		mid.executeForm(pardon);
		strong.executeForm(pardon);
		std::cout << "\n";

		std::cout << pardon << "\n";
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << "\n";
	}
	return 0;
}
