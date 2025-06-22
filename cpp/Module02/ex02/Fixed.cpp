/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 03:44:46 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/22 03:44:46 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ()
{
    this->rawBits = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &other)
{
    this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if(this != &other)
    {
        this->setRawBits(other.getRawBits());
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->rawBits;
}

void Fixed::setRawBits(int const raw)
{
    this->rawBits = raw;
}

Fixed::Fixed(const float f)
{
    this->rawBits = roundf(f * (1 << fractionalBits));
}

Fixed::Fixed(const int n)
{
    this->rawBits = n << fractionalBits;
}

float Fixed::toFloat() const
{
    return (float)this->rawBits / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return this-> rawBits >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->rawBits > other.rawBits;
}
bool Fixed::operator<(const Fixed &other) const
{
    return this->rawBits < other.rawBits;
}
bool Fixed::operator<=(const Fixed &other) const
{
    return this->rawBits <= other.rawBits;
}
bool Fixed::operator>=(const Fixed &other) const
{
    return this->rawBits >= other.rawBits;
}
bool Fixed::operator==(const Fixed &other) const
{
    return this->rawBits == other.rawBits;
}
bool Fixed::operator!=(const Fixed &other) const
{
    return this->rawBits != other.rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(this->rawBits + other.rawBits);
    return res;
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(this->rawBits - other.rawBits);
    return res;
}
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed res;
    res.setRawBits((this->rawBits * other.rawBits) >> fractionalBits);
    return res;
}
Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed res;
    res.setRawBits((this->rawBits << fractionalBits) / other.rawBits);
    return res;
}

Fixed &Fixed::operator++()
{
    this->rawBits = rawBits + 1;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->rawBits = rawBits + 1;
    return tmp;
}
Fixed &Fixed::operator--()
{
    this->rawBits = rawBits - 1;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->rawBits = rawBits - 1;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}
