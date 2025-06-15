#include "../include/FragTrap.hpp"
#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

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
