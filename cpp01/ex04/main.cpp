/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:12:17 by gorg              #+#    #+#             */
/*   Updated: 2025/05/31 20:53:24 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << av[0] << " <Filename> <Search String> <Replace String>" << std::endl;
		return 1;
	}


	std::string fileName = av[1];
	std::string searchName = av[2];
	std::string replaceName = av[3];
	if (searchName.empty())
	{
		std::cout << "Search string cannot be empty." << std::endl;
		return 1;
	}
	std::ifstream infile(fileName, std::ios::in | std::ios::binary);
	if (!infile)
	{
		std::cout << "Input" << std::endl;
		return (1);
	}

	std::string outName = fileName + ".replace";

	std::ofstream outfile(outName, std::ios::out | std::ios::binary);
	if (!outfile)
	{
		std::cout << "Output" << std::endl;
		infile.close();
		return (1);
	}
	

	std::ostringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();

	size_t pos = 0;
	while ((pos = content.find(searchName, pos)) != std::string::npos)
	{
		content.erase(pos, searchName.length());
		content.insert(pos, replaceName);
		pos += replaceName.length();
	}
	outfile << content;
	infile.close();
	outfile.close();
	return (0);
}