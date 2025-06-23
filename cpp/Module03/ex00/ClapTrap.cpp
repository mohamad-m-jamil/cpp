/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 03:59:03 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/23 03:59:03 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Default ClapTrap constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor called for " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack: no energy or hit points left." << std::endl;
        return;
    }
    this->energyPoints -= 1;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return;
    }

    if ((int)amount >= hitPoints)
    {
        hitPoints = 0;
    }
    else
    {
        hitPoints -= amount;
    }

    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot repair itself because it has no hit points or energy points left." << std::endl;
        return;
    }
    energyPoints -= 1;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount << " hit points!" << std::endl;
}
