/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:05:33 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/15 15:05:33 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

class PhoneBook {
    private:
      Contact contacts[8];
      int     index;
    public:
        PhoneBook();
        void addContact();
        void displayAllContacts() const;
        void searchContact() const;
};

#endif