/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <hoobird@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:51:55 by hoobird           #+#    #+#             */
/*   Updated: 2024/09/01 14:39:59 by hoobird          ###   ########.fr       */
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

  private:
	Contact contacts[8];
	int size;
	void printTable();
	void reverseRotate();
	void truncate10(std::string str);
};

#endif