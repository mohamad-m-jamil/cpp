/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 04:53:11 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/24 04:53:11 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called\n";
}

Animal::~Animal() {
    std::cout << "Animal destructor called\n";
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound...\n";
}

std::string Animal::getType() const {
    return type;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called\n";
    this->type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}
