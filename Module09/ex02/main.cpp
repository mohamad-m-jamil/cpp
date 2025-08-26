/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:44:00 by mjamil            #+#    #+#             */
/*   Updated: 2025/08/04 16:44:00 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cerr << "Error: Not enough arguments." << std::endl;
        return 1;
    }
    try {
        PmergeMe sorter;
        sorter.parseInput(argv);
        sorter.sortWithVector();
        sorter.sortWithDeque();
        sorter.displayResults();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}