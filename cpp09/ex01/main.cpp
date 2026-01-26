#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try {
		std::string b(av[1]);
		RPN a(b);}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "Error\n";
		}
	}
	else
		std::cout << "./RPN <numbers and operators>\n";
	return 0;
}
