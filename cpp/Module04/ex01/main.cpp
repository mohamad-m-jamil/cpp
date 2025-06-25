/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 04:39:16 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/24 04:39:16 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int size = 4;
    Animal* animals[size];

    std::cout << "=== Creating Animals ===" << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Making Sounds ===" << std::endl;
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();

    std::cout << "\n=== Testing Deep Copy ===" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "Sleep all day");

    Cat copiedCat = originalCat;  // Copy constructor

    std::cout << "Original Cat idea[0]: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat idea[0]: " << copiedCat.getBrain()->getIdea(0) << std::endl;

    copiedCat.getBrain()->setIdea(0, "Play all day");

    std::cout << "After modifying copiedCat's idea:" << std::endl;
    std::cout << "Original Cat idea[0]: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat idea[0]: " << copiedCat.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n=== Deleting Animals ===" << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}
