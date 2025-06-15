#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main() {
    const int size = 4;
    const Animal* animals[size];

    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    std::cout << "\nDeleting animals...\n";
    for (int i = 0; i < size; ++i)
        delete animals[i];

    std::cout << "\nTesting deep copy:\n";
    Dog dog1;
    dog1.makeSound();

    Dog dog2 = dog1; // copy constructor
    Dog dog3;
    dog3 = dog1;     // assignment operator

    return 0;
}