#include "../includes/Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructed\n";
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructed\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Cat copied\n";
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat assigned\n";
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!\n";
}
