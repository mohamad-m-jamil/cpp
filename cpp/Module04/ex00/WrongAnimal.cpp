/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 05:22:06 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/24 05:22:06 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes some generic sound...\n";
}

std::string WrongAnimal::getType() const
{
    return type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor called\n";
    this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignment operator called\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}
