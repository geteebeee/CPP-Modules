/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 00:21:01 by gorg              #+#    #+#             */
/*   Updated: 2026/01/26 23:27:22 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::printTimes(std::chrono::duration<double, std::micro> vec, std::chrono::duration<double, std::micro> deq)
{
	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << vec << std::endl
		<< "Time to process a range of " << _deq.size()
		<< " elements with std::deque : " << deq << std::endl;
}


int PmergeMe::parseArg(char *arg)
{
	if (arg == NULL)
		throw std::runtime_error("Error: NULL argument");

	for (int i = 0; arg[i] != '\0'; ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(arg[i])))
			throw std::runtime_error("Error: Not a digit");
	}

	long val = std::strtol(arg, 0, 10);
	if (arg[0] == '\0' || val <= 0 || val > std::numeric_limits<int>::max())
		throw std::runtime_error("Error: Not a valid number or duplicate");
	return static_cast<int>(val);
}

size_t PmergeMe::jNum(int pos)
{
	if (pos == 0)
		return 0;
	if (pos == 1)
		return 1;
	return static_cast<size_t>((std::pow(2.0, pos) - std::pow(-1.0, pos)) / 3.0);
}

void PmergeMe::loadFromArgs(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error");

	_vec.clear();
	_vec.reserve(argc - 1);
	_deq.clear();
	
	std::set<int> uniqueValues;
	for (int i = 1; i < argc; ++i)
	{
		int val = parseArg(argv[i]);
		if (!uniqueValues.insert(val).second)
			throw std::runtime_error("Error");
		_vec.push_back(val);
	}
	_deq.assign(_vec.begin(), _vec.end());
}



std::vector<size_t> PmergeMe::buildInsertionOrder(size_t count)
{
	std::vector<size_t> order;
	if (count == 0)
		return order;
	if (count == 1)
	{
		order.push_back(0);
		return order;
	}

	size_t previous = 0;
	for (size_t step = 2; previous < count; ++step)
	{
		size_t boundary = std::min(static_cast<size_t>(jNum(static_cast<int>(step))), count);
		
		if (boundary <= previous)
			continue;
		for (size_t idx = boundary; idx > previous; --idx)
			order.push_back(idx - 1);
		previous = boundary;
	}
	return order;
}

void PmergeMe::run(int argc, char **argv)
{
	auto start = std::chrono::high_resolution_clock::now();
	loadFromArgs(argc, argv);
	auto end = std::chrono::high_resolution_clock::now();

	if (std::is_sorted(_vec.begin(), _vec.end()) && std::is_sorted(_deq.begin(), _deq.end()))
	{
		std::cout << "Already sorted." << std::endl;
		return ;
	}

	printVals("Before:", _vec);

	auto sVec = std::chrono::high_resolution_clock::now();
	mergeInsertionSort(_vec);
	auto eVec = std::chrono::high_resolution_clock::now();
	
	auto sDeq = std::chrono::high_resolution_clock::now();
	mergeInsertionSort(_deq);
	auto eDeq = std::chrono::high_resolution_clock::now();

	auto parseTime = end - start;
	auto vecTime = eVec - sVec + parseTime;
	auto deqTime = eDeq - sDeq + parseTime;

	if (!std::is_sorted(_vec.begin(), _vec.end()) || !std::is_sorted(_deq.begin(), _deq.end()))
	{
		std::cout << "Sorting failed." << std::endl;
		return ;
	}
	
	printVals("After:", _vec);
	printTimes(vecTime, deqTime);
}
