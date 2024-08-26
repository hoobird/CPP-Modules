/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:55:25 by hoobird           #+#    #+#             */
/*   Updated: 2024/08/26 20:39:12 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook created" << std::endl;
	size = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	for (int i = 0; i < size; i++)
	{
		contacts[i].~Contact();
	}
	std::cout << "PhoneBook destructed" << std::endl;
}

void	PhoneBook::addContact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	Contact *newestContact;

	if (size == 8)
	{
		reverseRotate();
	}
	else
	{
		size++;
	}
	newestContact = &contacts[size - 1];
	
}

void	PhoneBook::reverseRotate(void)
{	
	Contact first;
	
	first = contacts[0];	
	for (int i = 0; i < size - 1; i++)
	{
		contacts[i] = contacts[i + 1];
	}
	contacts[size - 1] = first;
}


