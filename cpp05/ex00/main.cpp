#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;

		alice.increment();  // grade goes from 2 → 1
		std::cout << alice << std::endl;

		// This will throw (grade would go above limit)
		alice.increment();
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "----" << std::endl;

	try {
		Bureaucrat bob("Bob", 149);
		std::cout << bob << std::endl;

		bob.decrement();  // grade goes from 149 → 150
		std::cout << bob << std::endl;

		// This will throw (grade too low)
		bob.decrement();
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "----" << std::endl;

	try {
		// Invalid grade on construction → throws immediately
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl; // never reached
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
