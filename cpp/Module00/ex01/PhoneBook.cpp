/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:05:30 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/15 15:05:30 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

void PhoneBook::addContact()
{
    Contact newContact;
    newContact.setContact();

    if (newContact.getSummaryField(0).empty() ||
        newContact.getSummaryField(1).empty() ||
        newContact.getSummaryField(2).empty())
    {
        std::cout << "All fields must be filled. Contact not saved.\n";
        return;
    }

    int pos = index % 8;
    contacts[pos] = newContact;
    index++;
    std::cout << "Contact added at index " << pos << ".\n";
}

std::string formatField(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::displayAllContacts() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < (index < 8 ? index : 8); ++i)
    {
        std::cout << std::setw(10) << i << "|"
                  << formatField(contacts[i].getSummaryField(0)) << "|"
                  << formatField(contacts[i].getSummaryField(1)) << "|"
                  << formatField(contacts[i].getSummaryField(2)) << std::endl;
    }
}

void PhoneBook::searchContact() const
{
    if (index == 0)
    {
        std::cout << "PhoneBook is empty.\n";
        return;
    }

    displayAllContacts();

    std::cout << "Enter index of contact to display: ";
    int i;
    std::cin >> i;

    if (std::cin.fail() || i < 0 || i >= (index < 8 ? index : 8))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index.\n";
    }
    else
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        contacts[i].displayContact();
    }
}
