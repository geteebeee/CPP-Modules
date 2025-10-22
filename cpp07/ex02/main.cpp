#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	try
	{
		std::cout << "-------------------N" << std::endl;
		Array<int> numbers(5);
		for (unsigned int i = 0; i < numbers.size(); ++i)
			numbers[i] = i;

		
		for (unsigned int i = 0; i < numbers.size(); ++i)
			std::cout << numbers[i] << " ";
		std::cout << std::endl << "-------------------C" << std::endl;
		Array<int> copy(numbers);
		for (unsigned int i = 0; i < copy.size(); ++i)
			std::cout << copy[i] << " ";
		std::cout << std::endl;

		copy[1] = 42;
		std::cout << "-------------------N" << std::endl;

		for (unsigned int i = 0; i < numbers.size(); ++i)
			std::cout << numbers[i] << " ";
		std::cout << std::endl << "-------------------C" << std::endl;

		for (unsigned int i = 0; i < copy.size(); ++i)
			std::cout << copy[i] << " ";
		std::cout << std::endl << "--------------------" << std::endl;
		std::cout << "-N_SIZE " << numbers.size() << " -C_SIZE " << copy.size() << "-" << std::endl;
		std::cout << "-Exception incoming-" << std::endl;

		std::cout << numbers[6];
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
