/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <hoobird@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:51:55 by hoobird           #+#    #+#             */
/*   Updated: 2024/08/25 17:14:02 by hoobird          ###   ########.fr       */
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
    void add();
    void search();
private:
    Contact contacts[8];
    int size;  
};

#endif