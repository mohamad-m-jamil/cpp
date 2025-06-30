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
    brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    type = other.type;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Brain* Dog::getBrain() const
{
    return brain;
}