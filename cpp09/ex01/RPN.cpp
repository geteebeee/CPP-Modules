/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:49:19 by gorg              #+#    #+#             */
/*   Updated: 2025/10/11 15:49:19 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


static bool _isoperator(char n)
{
	return n == '+' || n == '-' || n == '/' || n == '*';
} 

RPN::RPN(std::string av)
{
	long result = 0;
	unsigned int i = 0;

	while(i < av.size())
	{
		if (std::isspace(static_cast<unsigned char>(av[i])))
		{
			i++;
			continue;
		}
		if (std::isdigit(static_cast<unsigned char>(av[i])) && (i + 1 == av.size() || std::isspace(static_cast<unsigned char>(av[i + 1]))))
		{
			int val = av[i] - '0';

			_line.push(val);
			i++;
			continue;
		}
		if (_isoperator(av[i]))
		{
			if (_line.size() < 2)
				throw std::runtime_error("Error: Wrong input");
			long b = _line.top();
			_line.pop();
			long a = _line.top();
			_line.pop();

			switch (av[i]) {
				case '+': result = a + b; break;
				case '-': result = a - b; break;
				case '*': result = a * b; break;
				case '/': if (b == 0) throw std::runtime_error("Error: Division by 0");  result = a / b; break;
			}
			if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
				throw std::overflow_error("Error: Overflow");
			_line.push(static_cast<int>(result));
			i++;
			continue;
			
		}
		else
			throw std::runtime_error("Error: Wrong input");
		i++;
	}
	if (_line.size() != 1)
		throw std::runtime_error("Error: Wrong input");
	result = _line.top();
	_line.pop();
	std::cout << result << std::endl;
}

RPN::~RPN() {}