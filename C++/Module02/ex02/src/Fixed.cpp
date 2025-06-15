#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n) {
    _value = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
    _value = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_value = other._value;
    return *this;
}

float Fixed::toFloat(void) const {
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const { return _value > other._value; }
bool Fixed::operator<(const Fixed& other) const { return _value < other._value; }
bool Fixed::operator>=(const Fixed& other) const { return _value >= other._value; }
bool Fixed::operator<=(const Fixed& other) const { return _value <= other._value; }
bool Fixed::operator==(const Fixed& other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed& other) const { return _value != other._value; }

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    --_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
