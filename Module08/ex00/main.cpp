/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:27:15 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/26 19:27:15 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    lst.push_back(45);

    try {
        std::vector<int>::iterator it_vec = easyfind(vec, 30);
        std::cout << "Found in vector: " << *it_vec << std::endl;

        std::list<int>::iterator it_lst = easyfind(lst, 25);
        std::cout << "Found in list: " << *it_lst << std::endl;

        std::vector<int>::iterator it_fail = easyfind(vec, 100);
        std::cout << "Found: " << *it_fail << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

