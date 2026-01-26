/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:25:08 by gorg              #+#    #+#             */
/*   Updated: 2025/10/09 21:42:25 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {};

static std::chrono::year_month_day parse_date(std::string date)
{
	if (!(date.size() == 10 && date[4] == '-' && date[7] == '-'))
		return {};
	struct s_date
	{
		int y;
		unsigned int m;
		unsigned int d;
	};

	s_date parsed;

	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return {};
	}

	parsed.y = std::stoi(date.substr(0, 4));
	parsed.m = std::stoi(date.substr(5, 2));
	parsed.d = std::stoi(date.substr(8, 2));

	std::chrono::year_month_day ymd
	{
		std::chrono::year{parsed.y},
		std::chrono::month{parsed.m},
		std::chrono::day{parsed.d}
	};

	if (!ymd.ok())
		return {};
	return ymd;
}

static std::string trim(std::string str)
{
	std::size_t first = str.find_first_not_of(" \t\r");
	if (first == std::string::npos)
		return std::string(); 
	std::size_t last = str.find_last_not_of(" \t\r");
	return str.substr(first, last - first + 1);
}

BitcoinExchange::BitcoinExchange(std::string file)
{
	std::ifstream input(file, std::ios::in);
	if (!input)
		throw std::runtime_error("Failed to open input");
	
	std::ifstream data("data.csv", std::ios::in);
	if (!data)
		throw std::runtime_error("Failed to open data");
	std::string line;
	std::getline(data, line);

	while (std::getline(data, line))
	{
		std::chrono::year_month_day date_split = parse_date(line.substr(0, 10));

		const std::string::size_type comma = line.find(',');
		if (comma == std::string::npos)
			continue ;	
		const std::string price_str = line.substr(comma + 1);
		float price = std::stof(price_str);

		_price[date_split] = price;
	}
	

	while (std::getline(input, line))
	{
		if (line == "date | value")
			continue;
		std::size_t bar = line.find('|');
		
		if (bar == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << '\n';
			continue;
		}

		std::chrono::year_month_day date_split = parse_date(trim(line.substr(0, bar)));
		if (!date_split.ok())
		{
			std::cout << "Error: bad date input in line => " << line << std::endl;
			continue ;
		}



		auto val = _price.lower_bound(date_split);

		if (val == _price.end())
		{
			if (_price.empty())
			{
				std::cout << "Error: bad input => " <<line << std::endl;
				continue;
			}
			val--;
		}

		else if (val->first != date_split)
		{
			if (val == _price.begin())
			{
				std::cout << "Error: bad input => " <<line << std::endl;
				continue;
			}
		val--;
		}
		
		double val1;
		std::string num = trim(line.substr(bar + 1));
		try
		{
			val1 = std::stod(num);
			if (!(val1 >= 0))
			{
				std::cout << "Error: not a positive number\n";
				continue;
			}
			else if (!(val1 <= 1000))
			{
				std::cout << "Error: too large of a number.\n";
				continue;
			}

			std::cout << static_cast<int>(date_split.year()) << "-" 
			<< std::setw(2) << std::setfill('0') << static_cast<unsigned int>(date_split.month()) << "-"
			<< std::setw(2) << std::setfill('0') << static_cast<unsigned int>(date_split.day()) << " => " 
			<< std::setfill(' ') << val1 <<  " = "  << (val->second * val1) <<std::endl;
		}

		catch(...)
		{
			std::cout <<"Error: Wrong formating in the quantity of asset\n";
		}
	}

}