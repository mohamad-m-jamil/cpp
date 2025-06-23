/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 05:03:07 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/23 05:03:07 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "\n--- Creating ClapTrap ---\n";
    ClapTrap clap("Clappy");

    std::cout << "\n--- Creating ScavTrap ---\n";
    ScavTrap scav("Scavy");

    std::cout << "\n--- Testing ClapTrap ---\n";
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n--- Testing ScavTrap ---\n";
    scav.attack("Big Enemy");
    scav.takeDamage(40);
    scav.beRepaired(20);
    scav.guardGate();

    std::cout << "\n--- End of main ---\n";
    return 0;
}