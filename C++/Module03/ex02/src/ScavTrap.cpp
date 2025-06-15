#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "Scavtrap " << _name << " constructed with custom stats!\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destroyed!\n";
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " can't attack. No HP or energy.\n";
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " launches a heavy attack on " << target
              << ", causing " << _attackDamage << " damage!\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!\n";
}