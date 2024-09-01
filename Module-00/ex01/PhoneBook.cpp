/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <hoobird@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:55:25 by hoobird           #+#    #+#             */
/*   Updated: 2024/09/01 14:43:17 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "main.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook created" << std::endl;
	size = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	// for (int i = 0; i < size; i++)
	// {
	// 	contacts[i].~Contact();
	// }
	// std::cout << "PhoneBook destructed" << std::endl;
}

void PhoneBook::addOption()
{
	std::string info[5];
	std::cout << "Enter first name: ";
	info[0] = myGetline();
	std::cout << "Enter last name: ";
	info[1] = myGetline();
	std::cout << "Enter nickname: ";
	info[2] = myGetline();
	std::cout << "Enter phone number: ";
	info[3] = myGetline();
	std::cout << "Enter darkest secret: ";
	info[4] = myGetline();
	// trim whitespaces and check if empty
	for (int i = 0; i < 5; i++)
	{
		info[i] = ft_trim(info[i]);
		if (info[i].empty())
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << "Add contact failed, returning to main menu" << std::endl;
			return ;
		}
	}
	if (size == 8)
		reverseRotate();
	else
		size++;
	contacts[size - 1].setFirstName(info[0]);
	contacts[size - 1].setLastName(info[1]);
	contacts[size - 1].setNickname(info[2]);
	contacts[size - 1].setPhoneNumber(info[3]);
	contacts[size - 1].setDarkestSecret(info[4]);
	std::cout << "Contact added" << std::endl;
}

void PhoneBook::searchOption()
{
	int i;
	i = 0;

	if (size == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		std::cout << "Search failed, returning to main menu" << std::endl;
		return ;
	}
	printTable();
	std::cout << "Enter index of contact: ";
	std::cin >> i;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (i < 1 || i > size)
	{
		std::cout << "Input is not within the range" << std::endl;
		std::cout << "Search failed, returning to main menu" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "First name: " << contacts[i - 1].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[i - 1].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[i - 1].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[i - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[i - 1].getDarkestSecret() << std::endl;
}

void PhoneBook::printTable()
{
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "|         " << i + 1 << "|";
		truncate10(contacts[i].getFirstName());
		std::cout << "|";
		truncate10(contacts[i].getLastName());
		std::cout << "|";
		truncate10(contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}
void PhoneBook::truncate10(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setw(10) << str;
	}
}

void PhoneBook::reverseRotate(void)
{
	Contact	first;

	first = contacts[0];
	for (int i = 0; i < size - 1; i++)
	{
		contacts[i] = contacts[i + 1];
	}
	contacts[size - 1] = first;
}
