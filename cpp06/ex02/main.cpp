/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 00:54:17 by gorg              #+#    #+#             */
/*   Updated: 2025/09/30 00:54:17 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <string>
#include <ctime>
#include <iostream>


//It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
//to use anything you like for the random choice implementation.
Base * generate(void)
{
	int val = rand() % 3;
	if (val == 2)
		return new A;
	else if (val == 1)
		return new B;
	else
		return new C;
}

//It prints the actual type of the object pointed to by p: "A", "B", or "C".

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n\n";
	else
		std::cout << "Something else happened\n\n";
}

// t prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.


void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A Ref Found\n";
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		B &a = dynamic_cast<B&>(p);
		(void)a;

		std::cout << "B Ref Found\n";
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		C &a = dynamic_cast<C&>(p);
		(void)a;

		std::cout << "C Ref Found\n";
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "Reference not found\n";
}

int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	for (int i = 0; i < 10 ; i++)
	{
		std::cout << "----------Run " << i << std::endl;
		Base *a = generate();
		(void)a;
		identify(a);
		identify(*a);
		delete a;
	}
	return 0;
}

