/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:56:46 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/19 10:56:46 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "[ DEBUG ]" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "[ INFO ]" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "[ WARNING ]" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "[ ERROR ]" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "[ UNKNOWN ]" << std::endl;
    harl.complain("WHATEVER");
    std::cout << std::endl;

    return 0;
}
