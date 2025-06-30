/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 05:11:53 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/24 05:11:53 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat constructor called\n";
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called\n";
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}
