/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 05:04:39 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/24 05:04:39 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor called\n";
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called\n";
    this->type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}
