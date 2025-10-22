#include "Span.hpp"
#include <iostream>
#include <limits.h>
#include <exception>
#include <vector>
#include <list>
int main()
{
	try {
		Span sp = Span(6);
		sp.addNumber(10);
		sp.addNumber(INT_MIN);
		sp.addNumber(3);
		sp.addNumber(INT_MAX);
		sp.addNumber(20);
		sp.addNumber(7);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		Span sp2 = Span(500);
		std::vector<int> values;
		for (int i = 1; i <= 499; ++i)
			values.push_back(i);
		sp2.addNumber(values.begin(), values.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
		for (int n : sp2.getNumbers()) {
			std::cout << n << ' ';}
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp3 = Span(2);
		sp3.addNumber(10);
		sp3.addNumber(10);
		sp3.addNumber(10);
		sp3.addNumber(10);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp4 = Span(2);
		sp4.addNumber(1);
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp5 = Span(2);
		std::vector<int> values;
		for (int i = 1; i <= 499; ++i)
			values.push_back(i);
		sp5.addNumber(values.begin(), values.end());
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
        Span ss(5);
        std::list<int> intLst = {5, -2147483648, 10, 1, 2147483647};
        ss.addNumber(intLst.begin(), intLst.end());
        std::cout << ss.longestSpan() << std::endl;
        std::cout << ss.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	return 0;
}
