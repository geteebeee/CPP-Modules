#include <iostream>
#include <list>
#include <unordered_set>
#include "Array.hpp"
#include <vector>

int main()
{
	try
	{
		std::vector<int> vec{1,2,3};
		const std::list<int> lst{4,5,6};
		std::unordered_set<int> uset{7,8,9};
		auto it1 = easyfind(vec, 2); 
		auto it2 = easyfind(lst, 5);
		auto it3 = easyfind(uset, 9);
		std::cout << "Value found vec: " << *it1 <<  " Value found lst: " << *it2 <<  " Value found uset: " << *it3<<std::endl;
		std::cout << "--Exception throwing--" << std::endl;
		easyfind(vec, 42);
	
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}