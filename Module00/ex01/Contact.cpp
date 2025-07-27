/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:05:20 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/15 15:05:20 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setContact()
{
    std::cout << "Enter First Name: ";
    std::getline(std::cin, first_name);
    if (first_name.empty())
        return;

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, last_name);
    if (last_name.empty())
        return;

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    if (nickname.empty())
        return;

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phone_number);
    if (phone_number.empty())
        return;

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkest_secret);
    if (darkest_secret.empty())
        return;
}

void Contact::displayContact() const
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name <<  std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

std::string Contact::getSummaryField(int fieldIndex) const
{
    if(fieldIndex == 0)
        return(first_name);
    else if(fieldIndex == 1)
        return(last_name);
    else if(fieldIndex == 2)
        return(nickname);
    else
        return "";
}

