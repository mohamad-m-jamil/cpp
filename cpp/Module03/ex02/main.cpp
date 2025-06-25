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
#include "FragTrap.hpp"

int main() {
    std::cout << "\n--- Creating ClapTrap ---\n";
    ClapTrap clap("Clappy");

    std::cout << "\n--- Creating ScavTrap ---\n";
    ScavTrap scav("Scavy");

    std::cout << "\n--- Creating FragTrap ---\n";
    FragTrap frag("Fraggy");

    std::cout << "\n--- Testing ClapTrap ---\n";
    clap.attack("Enemy");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << "\n--- Testing ScavTrap ---\n";
    scav.attack("Robot");
    scav.guardGate();

    std::cout << "\n--- Testing FragTrap ---\n";
    frag.attack("MegaBot");
    frag.highFivesGuys();

    std::cout << "\n--- End of main ---\n";
    return 0;
}