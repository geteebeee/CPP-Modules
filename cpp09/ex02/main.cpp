#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
		{
			std::cout << "Error\n";
			return 1;
		}
		PmergeMe sorter;
		sorter.run(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		std::cout << "Something which was not thrown was catched" << std::endl;
		return 1;
	}
	return 0;
}
