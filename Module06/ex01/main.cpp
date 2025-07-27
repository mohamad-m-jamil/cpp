/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:00:24 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/20 16:46:43 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"
#include <cstddef>

int main() {
    Data data;
    data.age = 21;
    data.name = "Jamil";

    Data* ptr = &data;

    size_t raw = Serializer::serialize(ptr);
    Data* newPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Deserialized pointer: " << newPtr << std::endl;

    if (newPtr == ptr) {
        std::cout << "Pointers are equal! Serialization works." << std::endl;
        std::cout << "Age: " << newPtr->age << ", Name: " << newPtr->name << std::endl;
    } else {
        std::cout << "Pointers are NOT equal. Something went wrong." << std::endl;
    }

    return 0;
}
