#include "../include/ClapTrap.hpp"

int main()
{
    ClapTrap clap("Clappy");

    clap.attack("Enemy");
    clap.takeDamage(4);
    clap.beRepaired(3);
    clap.attack("Enemy again");
    clap.takeDamage(10);
    clap.beRepaired(2);
    clap.attack("Last enemy");

    return 0;
}
