/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:41:31 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/21 15:19:13 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
    size_t i = 0;
    while(i < length)
    {
        func(array[i]);
        i++;
    }
}

#endif