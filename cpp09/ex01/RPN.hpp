/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:31:58 by gorg              #+#    #+#             */
/*   Updated: 2025/10/11 15:31:58 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stack>
#include <limits>
#include <stdexcept>

class RPN
{
	private:
		std::stack<int> _line;
	public:
		RPN(std::string av);
		~RPN();
};