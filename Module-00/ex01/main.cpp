/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <hoobird@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:55:00 by hoobird           #+#    #+#             */
/*   Updated: 2024/08/28 23:57:06 by hoobird          ###   ########.fr       */
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
	
	contact.setFirstName("Alice");
	contact.setLastName("Smith");
	contact.setNickname("Ally");
	contact.setPhoneNumber("1112223333");
	contact.setDarkestSecret("I love chocolate");
	phoneBook->contacts[2] = contact;
	
	contact.setFirstName("Bob");
	contact.setLastName("Brown");
	contact.setNickname("Bobby");
	contact.setPhoneNumber("4445556666");
	contact.setDarkestSecret("I hate Mondays");
	phoneBook->contacts[3] = contact;
	
	contact.setFirstName("Charlie");
	contact.setLastName("Davis");
	contact.setNickname("Chuck");
	contact.setPhoneNumber("7778889999");
	contact.setDarkestSecret("I am afraid of heights");
	phoneBook->contacts[4] = contact;
	
	contact.setFirstName("Diana");
	contact.setLastName("Evans");
	contact.setNickname("Di");
	contact.setPhoneNumber("0001112222");
	contact.setDarkestSecret("I love cats");
	phoneBook->contacts[5] = contact;
	
	contact.setFirstName("Eve");
	contact.setLastName("Foster");
	contact.setNickname("Evie");
	contact.setPhoneNumber("3334445555");
	contact.setDarkestSecret("I am a night owl");
	phoneBook->contacts[6] = contact;
	
	contact.setFirstName("Frank");
	contact.setLastName("Green");
	contact.setNickname("Frankie");
	contact.setPhoneNumber("6667778888");
	contact.setDarkestSecret("I am a morning person");
	phoneBook->contacts[7] = contact;
	phoneBook->size = 8;
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
		if (input.compare("EXIT") == 0 || input.empty())
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
