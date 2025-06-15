#include "../include/ScavTrap.hpp"
#include "../include/ClapTrap.hpp"

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
