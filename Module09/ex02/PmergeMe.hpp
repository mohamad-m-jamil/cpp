/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:51:56 by mjamil            #+#    #+#             */
/*   Updated: 2025/08/12 21:51:56 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
    private:
        std::vector<int> vec_container;
        std::deque<int> deq_container;
        double vector_time;
        double deque_time;
        std::vector<int> original_input;
        bool is_recursive_call;
        size_t vec_comparisons;
        size_t deq_comparisons;
    public:
        PmergeMe();
        void parseInput(char** argv);
        void sortWithVector();
        void sortWithDeque();
        void displayResults();
};

#endif