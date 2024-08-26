/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:51:55 by hoobird           #+#    #+#             */
/*   Updated: 2024/08/26 21:56:22 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  public:
    PhoneBook(void);
    ~PhoneBook(void);
    void addContact();
    void search();
  private:
    Contact contacts[8];
    int size;
    void reverseRotate();
    
};

#endif