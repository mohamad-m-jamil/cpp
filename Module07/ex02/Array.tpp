/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:21:21 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/27 15:32:28 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//When you define a template class, all its
//implementation must be visible to
//the compiler when you use it


#include "Array.hpp"

template <typename T>
Array<T>::Array () : _array(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(other._size)
{
    if(_size > 0)
    {
        _array = new T[_size];
        unsigned int i = 0;
        while(i < _size)
        {
            _array[i] = other._array[i];
            i++;
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if(this != &other)
    {
        delete[] _array;
        _size = other._size;
        if(_size > 0)
        {
            _array = new T[_size];
            unsigned int i = 0;
            while(i < _size)
            {
                _array[i] = other._array[i];
                i++;
            }
        }
        else
        {
            _array = NULL;
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const 
{
    return _size;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}
