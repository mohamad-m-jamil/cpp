/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:13:28 by hsarraj           #+#    #+#             */
/*   Updated: 2025/04/22 15:13:28 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"
#include "../include/contact.hpp"


int main(void)
{
	PhoneBook 	PhoneBook;
	bool		run = true;
	std::string	command;

	PhoneBook.show_instruction();
	std::cout << "> ";
	while (run && std::getline(std::cin, command))
	{
		if (std::cin.eof() == true)
		{
			std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
			exit(0);
		}
		else if (command.compare("ADD") == 0)
			PhoneBook.set_information();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.get_information();
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "\033[34mHope i served you well. Good Bye.\033[0m" << std::endl;
			run = false;
			continue ;
		}
		command.clear();
		PhoneBook.show_instruction();
		std::cout << "> ";
	}
	if (run)
	{
		std::cout << "You pressed ^D, exiting now." << command << std::endl
		<< "\033[34mHope i served you well. Good Bye.\033[0m" << std::endl;
	}
	return (0);
}
