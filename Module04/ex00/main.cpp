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

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Correct Animal classes ===" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    dog->makeSound();  // Woof! Woof!
    cat->makeSound();  // Meow! Meow!

    delete dog;
    delete cat;

    std::cout << "\n=== Wrong Animal classes ===" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();

    wrongCat->makeSound(); 

    delete wrongCat;

    return 0;
}

