#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destroyed\n";
}

void ClapTrap::attack(const std::string& target)
{
    if(_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " Can't attack. No HP or energy left.\n";
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!\n";
}


void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " damage! Remaining HP: " << _hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't repair. No HP or energy left.\n";
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs " << amount
              << " HP! Current HP: " << _hitPoints << "\n";
}