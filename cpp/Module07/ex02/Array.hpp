/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:20:59 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/21 16:39:32 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

template <typename T>
class Array
{
    private:
        T array*;
        unsigned int size;
    public:
        Array();
        Array(const Array& other);
        Array& operator=(const Array& other)
        ~Array();

        Array(unsigned int n);
};

#endif