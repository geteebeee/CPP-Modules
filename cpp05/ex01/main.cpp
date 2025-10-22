#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat alice("Alice", 40);
		Bureaucrat bob("Bob", 120);
		Bureaucrat edge("Edge", 1);
		// Bureaucrat edge2("Edge2", 151);
		Bureaucrat edge3("Edge3", 1);

		Form tax("TaxForm", 50, 20);   // needs grade ≤50 to sign, ≤20 to exec
		Form leave("LeaveForm", 100, 80);
		Form low("Low", 1, 1);
		Form High("High", 150, 150);
		// Form Out("Out", 1, 0);
		// Form Out2("Out2", 1, 151);



		std::cout << tax << std::endl;
		std::cout << leave << std::endl;
		std::cout << low << std::endl;
		std::cout << High << std::endl;
		// std::cout << Out << std::endl;
		// std::cout << Out2 << std::endl;


		// Alice should succeed in signing TaxForm (40 ≤ 50)
		alice.signForm(tax);
		// Bob should fail in signing TaxForm (120 > 50)
		bob.signForm(tax);
		// Bob should succeed in signing LeaveForm (120 ≤ 100? nope → fail)
		bob.signForm(leave);

		//edge.signForm(low);
		//edge.signForm(High);
		// edge.signForm(Out);
		// edge.signForm(Out2);
		edge3.signForm(low);
		edge3.signForm(High);
		edge3.signForm(low);

		std::cout << "After signing attempts:" << std::endl;
		std::cout << tax << std::endl;
		std::cout << leave << std::endl;

		std::cout << low << std::endl;
		std::cout << High << std::endl;
		// std::cout << Out << std::endl;
		// std::cout << Out2 << std::endl;

	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
