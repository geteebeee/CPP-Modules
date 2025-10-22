#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include "Brain.hpp"

int main() {
	const int N = 4;
	Animal* animals[N];
	Animal test;

	for (int i = 0; i < N; ++i)
		animals[i] = (i < N / 2) ? static_cast<Animal*>(new Dog()) : static_cast<Animal*>(new Cat());

	for (int i = 0; i < N; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	Dog d1;
	d1.setIdea(0, "Chase the ball");
	Dog d2 = d1;
	d1.setIdea(0, "Guard the house");
	std::cout << "d1 idea[0]: " << d1.getIdea(0) << "\n";
	std::cout << "d2 idea[0]: " << d2.getIdea(0) << "\n";

	Cat c1;
	c1.setIdea(1, "Nap on keyboard");
	Cat c2;
	c2 = c1;
	c1.setIdea(1, "Knock glass off table");
	std::cout << "c1 idea[1]: " << c1.getIdea(1) << "\n";
	std::cout << "c2 idea[1]: " << c2.getIdea(1) << "\n";

	for (int i = 0; i < N; ++i)
		delete animals[i];

	return 0;
}
