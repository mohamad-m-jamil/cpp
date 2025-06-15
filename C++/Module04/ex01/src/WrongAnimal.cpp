#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal constructed\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "WrongAnimal copied\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        type = other.type;
    std::cout << "WrongAnimal assigned\n";
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound\n";
}

std::string WrongAnimal::getType() const
{
    return type;
}
