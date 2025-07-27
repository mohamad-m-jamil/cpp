/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:41:21 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/21 15:20:08 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// void printElement(int& x) {
//     std::cout << x << std::endl;
// }

// int main() {
//     int arr[] = {10, 20, 30, 40, 50};
//     size_t len = sizeof(arr) / sizeof(arr[0]);

//     iter(arr, len, printElement);

//     return 0;
// }

void printWithPrefix(std::string& s) {
    std::cout << "Item: " << s << std::endl;
}

int main() {
    std::string arr[] = {"apple", "banana", "cherry", "date"};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    ::iter(arr, len, printWithPrefix);

    return 0;
}