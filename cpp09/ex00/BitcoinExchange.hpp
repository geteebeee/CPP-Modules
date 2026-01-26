/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:40:28 by gorg              #+#    #+#             */
/*   Updated: 2025/10/09 20:36:31 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iomanip>

class BitcoinExchange
{
	private:
		std::map<std::chrono::year_month_day, float> _price;
	public:
		BitcoinExchange() = delete;
		~BitcoinExchange();
		BitcoinExchange(std::string file);
};