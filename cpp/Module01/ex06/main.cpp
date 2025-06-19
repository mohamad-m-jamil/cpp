/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:58:13 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/19 11:58:13 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int getLevel(std::string level) {
    if (level == "DEBUG")
        return 0;
    else if (level == "INFO")
        return 1;
    else if (level == "WARNING")
        return 2;
    else if (level == "ERROR")
        return 3;
    else
        return -1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <LEVEL>" << std::endl;
        return 1;
    }

    std::string level = argv[1];
    int lvl = getLevel(level);
    Harl harl;

    switch (lvl) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
            std::cout << std::endl;
            // fall through

        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
            std::cout << std::endl;
            // fall through

        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
            std::cout << std::endl;
            // fall through

        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            break;

        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }

    return 0;
}