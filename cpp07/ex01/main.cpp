#include "iter.hpp"
#include <iostream>

void inc(int &a) { a++; }

int main()
{
	int a[] = {1,2,3,4,5,6};

	for (int x : a)
		std::cout << x << " ";
	std::cout << "\n";

	iter(a, 6, inc);

	for (int x : a)
		std::cout << x << " ";
	std::cout << "\n";

	int b[] = {6,5,4,3,2,1};

	for (int x : b)
		std::cout << x << " ";
	std::cout << "\n";

	iter(b, 6, inc);

	for (int x : b)
		std::cout << x << " ";
	std::cout << "\n";
}
