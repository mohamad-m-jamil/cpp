/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:51:56 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/18 13:51:56 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if(this->weapon != NULL)
    {
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    }
    else
        std::cout << this->name << " has no weapon to attack with!" << std::endl;
}