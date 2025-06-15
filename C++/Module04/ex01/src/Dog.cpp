#include "../includes/Dog.hpp"

Dog::Dog() 
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructed\n";
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructed\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog copied\n";
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog assigned\n";
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!\n";
}