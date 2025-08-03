/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:38:04 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/20 22:05:54 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL))); // seed the random generator

    for (int i = 0; i < 5; ++i) {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        
        Base* obj = generate();

        std::cout << "Identify using pointer: ";
        identify(obj);

        std::cout << "Identify using reference: ";
        identify(*obj);

        std::cout << "-----------------------------" << std::endl;

        delete obj;
    }

    return 0;
}
