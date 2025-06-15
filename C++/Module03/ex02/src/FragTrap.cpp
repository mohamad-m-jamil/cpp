#include "../include/FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " has entered the battle arena!\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " has left the arena!\n";
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "FragTrap " << _name << " can't attack. No HP or energy.\n";
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " throws a deadly punch at " << target
              << ", dealing " << _attackDamage << " damage!\n";
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests a high five!\n";
}
