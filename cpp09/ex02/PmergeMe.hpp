/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 00:11:50 by gorg              #+#    #+#             */
/*   Updated: 2026/01/26 23:30:03 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <chrono>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>


class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		int comp = 0;
		int parseArg(char *arg);
		void loadFromArgs(int argc, char **argv);

		void printTimes(std::chrono::duration<double, std::micro> vec, std::chrono::duration<double, std::micro> deq);
		std::vector<size_t> buildInsertionOrder(size_t count);
		size_t jNum(int pos);


		template <typename Container>
		void printVals(std::string msg, Container &vals)
		{
			std::cout << msg << " ";
			for (typename Container::iterator it = vals.begin(); it != vals.end(); ++it)
			{
				if (it != vals.begin())
					std::cout << " ";
				std::cout << *it;
			}
			std::cout << std::endl;
		}


		template <typename Container>
		void copyBlock(Container& dest, const Container& src, size_t start, size_t len)
		{
			for (size_t i = 0; i < len; ++i)
			{
				if (start + i < src.size())
					dest.push_back(src[start + i]);
			}
		}

		template <typename Container>
		void mergeInsertionSort(Container &container, size_t factor = 1)
		{
			size_t n = container.size();
			if (n < 2 * factor)
				return ;


			size_t pairCount = n / (2 * factor);
			for (size_t i = 0; i < pairCount; ++i)
			{
				size_t start = i * 2 * factor;
				this->comp++;
				if (container[start + factor - 1] > container[start + 2 * factor - 1])
				{
					typename Container::iterator it = container.begin();
					std::swap_ranges(it + start,
									it + start + factor,
									it + start + factor);
				}
			}
			mergeInsertionSort(container, factor * 2);

			std::vector<size_t> chain; 
			chain.push_back(0); 

			for (size_t i = 0; i < pairCount; ++i)
			{
				chain.push_back(i * 2 * factor + factor);
			}

			std::vector<size_t> pendIdx; 
			for (size_t i = 1; i < pairCount; ++i)
			{
				pendIdx.push_back(i * 2 * factor); 
			}
			if (n >= (pairCount * 2 * factor) + factor)
			{
				pendIdx.push_back(pairCount * 2 * factor);
			}

			std::vector<size_t> order = buildInsertionOrder(pendIdx.size());

			for (size_t k = 0; k < order.size(); ++k)
			{
				size_t idx = order[k];
				size_t blockStart = pendIdx[idx];
				auto blockLeader = container[blockStart + factor - 1];
				auto searchEnd = chain.end();
				bool isStraggler = (blockStart == pairCount * 2 * factor);

				if (!isStraggler)
				{
					 size_t leaderIdx = blockStart + factor;
					 for(auto it = chain.begin(); it != chain.end(); ++it)
					 {
						 if (*it == leaderIdx)
						 {
							 searchEnd = it;
							 break;
						 }
					 }
				}

				auto pos = std::upper_bound(chain.begin(), searchEnd, blockLeader, [&](auto val, size_t bIndex)
				{
						this->comp++;
						return val < container[bIndex + factor - 1];
					}
				);
				chain.insert(pos, blockStart);
			}

			Container newContainer;
			for (size_t blockIdx : chain)
			{
				copyBlock(newContainer, container, blockIdx, factor);
			}
			
			size_t processedSize = chain.size() * factor;
			if (processedSize < n)
			{
				copyBlock(newContainer, container, processedSize, n - processedSize);
			}
			
			container = newContainer;
		}

	public:
		PmergeMe();
		~PmergeMe();

		void run(int argc, char **argv);
};
