/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 05:23:34 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/24 05:23:34 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat meows... but maybe not!\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called\n";
    this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator called\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}
