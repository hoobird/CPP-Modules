/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:55:17 by hoobird           #+#    #+#             */
/*   Updated: 2024/08/26 21:55:49 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructed" << std::endl;
	return;
}

void	Contact::setFirstName(std::string first_name)
{
	this->first_name = first_name;
}

void	Contact::setLastName(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phone_number)
{
	this->phone_number = phone_number;
}

void	Contact::setDarkestSecret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

std::string	Contact::getFirstName(void) const
{
	return (this->first_name);
}

std::string	Contact::getLastName(void) const
{
	return (this->last_name);
}

std::string	Contact::getNickname(void) const
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->phone_number);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->darkest_secret);
}
