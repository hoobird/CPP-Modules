/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:55:00 by hoobird           #+#    #+#             */
/*   Updated: 2024/08/28 23:08:53 by hulim            ###   ########.fr       */
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

void	addfakes(PhoneBook *phoneBook)
{
	Contact contact;
	contact.setFirstName("John");
	contact.setLastName("Doe");
	contact.setNickname("JD");
	contact.setPhoneNumber("1234567890");
	contact.setDarkestSecret("I am a fake contact");
	phoneBook->contacts[0] = contact;
	contact.setFirstName("abcdefghijklmnop"); // after j its 10
	contact.setLastName("Doe");
	contact.setNickname("Jane");	
	contact.setPhoneNumber("0987654321");
	contact.setDarkestSecret("I am also a fake contact");
	phoneBook->contacts[1] = contact;
	phoneBook->size = 2;
}

int	main(void)
{
	PhoneBook phoneBook;
	std::string input;
		
	std::cout << "\nWelcome to my AWESOME PHONEBOOK" << std::endl;
	// adding fakes must private contacts array
	addfakes(&phoneBook);
	while (1)
	{
		std::cout << "\nPlease enter one of the following options:" << std::endl;
		std::cout << "< ADD > | <SEARCH > | < EXIT>" << std::endl;
		input = myGetline();
		if (input.compare("ADD") == 0)
		{
			phoneBook.addOption();
		}
		else if (input.compare("SEARCH") == 0)
		{
			phoneBook.searchOption();
		}
		else if (input.compare("EXIT") == 0 || input.empty())
			break;
		else
			std::cout << "Invalid input" << std::endl;
	}
	std::cout << "Program is exiting" << std::endl;
	return (0);
}
