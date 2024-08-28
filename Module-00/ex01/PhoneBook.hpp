/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:51:55 by hoobird           #+#    #+#             */
/*   Updated: 2024/08/28 23:06:54 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);
	void addOption();
	void searchOption();
	Contact contacts[8];
	int size;

  private:
	void printTable();
	void reverseRotate();
	void truncate10(std::string str);
};

#endif