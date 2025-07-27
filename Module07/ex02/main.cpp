/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:21:01 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/27 15:30:49 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    try
    {
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); ++i)
            a[i] = i * 10;

        std::cout << "Array a:" << std::endl;
        for (unsigned int i = 0; i < a.size(); ++i)
            std::cout << "a[" << i << "] = " << a[i] << std::endl;

        Array<int> b = a; // Copy constructor
        b[0] = 999;

        std::cout << "\nArray b (after copying a and modifying b[0]):" << std::endl;
        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << "b[" << i << "] = " << b[i] << std::endl;

        std::cout << "\nArray a (should remain unchanged):" << std::endl;
        for (unsigned int i = 0; i < a.size(); ++i)
            std::cout << "a[" << i << "] = " << a[i] << std::endl;

        std::cout << "\nTrying to access out-of-bounds index:" << std::endl;
        std::cout << a[10] << std::endl; // Should throw

    }
    catch (std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
