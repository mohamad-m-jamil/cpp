/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:05:27 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/15 15:05:27 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;

    std::cout << "Welcome to your awesome PhoneBook!\n";
    std::cout << "Type ADD, SEARCH, or EXIT:\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "EXIT") {
            std::cout << "Goodbye!\n";
            break;
        } else if (std::cin.eof()) {
            std::cout << "\nEOF detected. Exiting.\n";
            break;
        } else {
            std::cout << "Unknown command. Try ADD, SEARCH, or EXIT.\n";
        }
    }

    return 0;
}