/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:55:00 by hoobird           #+#    #+#             */
/*   Updated: 2024/09/16 20:36:22 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string	myGetline(void)
{
	std::string line;
	std::getline(std::cin, line);
	if (std::cin.eof() || std::cin.fail())
	{
		// std::cout << "EOF detected" << std::endl;
		clearerr(stdin);
		std::cin.clear();
		return ("");
	}
	return (line);
}

std::string ft_trim(std::string str)
{
	std::string::size_type start = str.find_first_not_of(" \t");
	std::string::size_type end = str.find_last_not_of(" \t");
	if (start == std::string::npos)
	{
		return ("");
	}
	return (str.substr(start, end - start + 1));
}

int	main(void)
{
	PhoneBook phoneBook;
	std::string input;
		
	std::cout << "\nWelcome to my AWESOME PHONEBOOK" << std::endl;
	// adding fakes must private contacts array
	// addfakes(&phoneBook);
	while (1)
	{
		std::cin.clear();
		std::cout << "\nPlease enter one of the following options:" << std::endl;
		std::cout << "< ADD > | < SEARCH > | < EXIT >" << std::endl;
		input =ft_trim(myGetline());
		if (input.compare("EXIT") == 0)
			break;
		else if (input.compare("ADD") == 0)
		{
			phoneBook.addOption();
		}
		else if (input.compare("SEARCH") == 0)
		{
			phoneBook.searchOption();
		}
		else
			std::cout << "Invalid input" << std::endl;
	}
	std::cout << "Program is exiting" << std::endl;
	return (0);
}
