#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat constructed\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructed\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copied\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    WrongAnimal::operator=(other);
    std::cout << "WrongCat assigned\n";
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow? (wrong)\n";
}
