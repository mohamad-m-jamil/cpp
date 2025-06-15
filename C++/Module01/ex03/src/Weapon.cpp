#include "../include/Weapon.hpp"

// Constructor
Weapon::Weapon(const std::string& type) : type(type) {}

// Getter
const std::string& Weapon::getType() const {
    return this->type;
}

// Setter
void Weapon::setType(const std::string& type) {
    this->type = type;
}
