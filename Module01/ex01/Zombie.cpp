/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:28:39 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/17 14:28:39 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::Zombie(std::string name) : name(name){};

Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << " BraiiiiiiinnnzzzZ... " << std::endl;
}

void Zombie::setName(std::string newName)
{
    name = newName;
}