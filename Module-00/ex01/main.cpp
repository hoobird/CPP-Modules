/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:55:00 by hoobird           #+#    #+#             */
/*   Updated: 2024/08/26 21:53:16 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	PhoneBook phoneBook;
	std::string input;
		
	std::cout << "\nWelcome to my AWESOME PHONEBOOK" << std::endl;

	while (1)
	{
		std::cout << "Please enter one of the following options:" << std::endl;
		std::cout << "< ADD > | <SEARCH > | < EXIT>" << std::endl;
		std::cin >> input;
		if (input.compare("ADD") == 0)
		{
			std::cout << "WIP" << std::endl;
			continue;
		}
		else if (input.compare("SEARCH") == 0)
		{
			std::cout << "WIP" << std::endl;
			continue;
		}
		else if (input.compare("EXIT") == 0 || std::cin.eof())
			break;
		else
			std::cout << "Invalid input" << std::endl;
	}
	phoneBook.~PhoneBook();
	std::cout << "Program is exiting" << std::endl;
	return (0);
}
