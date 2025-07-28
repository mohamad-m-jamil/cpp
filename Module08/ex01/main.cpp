/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:07:17 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/26 20:07:17 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}

// #include "Span.hpp"
// #include <iostream>
// #include <cstdlib>     // For rand()
// #include <ctime>       // For time()
// #include <vector>

// int main()
// {
//     // Seed the random number generator
//     std::srand(static_cast<unsigned int>(std::time(NULL)));

//     try {
//         // Create a Span with capacity for 10,000 numbers
//         Span sp(10000);

//         // Fill with random numbers
//         for (int i = 0; i < 10000; ++i)
//             sp.addNumber(std::rand());

//         std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//         std::cout << "Longest span : " << sp.longestSpan() << std::endl;
//     }
//     catch (const std::exception& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     return 0;
// }
