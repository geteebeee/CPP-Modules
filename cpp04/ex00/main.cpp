

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
/////////////
const WrongAnimal* wrong = new WrongCat();
std::cout << wrong->getType() << std::endl;
wrong->makeSound();
delete wrong;
delete i;
delete j;
delete meta;
return 0;
}