/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:20:59 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/27 15:34:04 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <stdexcept> // for std::out_of_range

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;
    public:
        Array();
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        Array(unsigned int n);
        T& operator[](unsigned int index);//like arr[2] = 42
        const T& operator[](unsigned int index) const;
        unsigned int size() const;//This gives you the number of elements stored in your array.
};


#include "Array.tpp"

#endif