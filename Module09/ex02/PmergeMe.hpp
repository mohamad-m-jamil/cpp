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

class PmergeMe {
public:
    // Orthodox form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void processAndSort(int argc, char* argv[]);

private:
    // Parsing & validation
    bool isNumber(const std::string &s);
    bool hasDuplicate(const std::vector<int> &arr);
    std::vector<int> parseNumbers(int argc, char* argv[]);

    // Vector implementation
    std::vector<int> fordJohnsonSortVector(const std::vector<int>& input);
    void mergeInsertionVector(std::vector<int>& mainChain, const std::vector<int>& pendChain);
    std::vector<int> generateJacobsthalIndices(int pendSize);
    void binaryInsertVector(std::vector<int>& mainChain, int value, int upperBound);

    // Deque implementation  
    std::deque<int> fordJohnsonSortDeque(const std::vector<int>& input);
    void mergeInsertionDeque(std::deque<int>& mainChain, const std::deque<int>& pendChain);
    void binaryInsertDeque(std::deque<int>& mainChain, int value, int upperBound);

    // Utility functions
    void displaySequence(const std::vector<int>& seq, const std::string& label);
    double getCurrentTimeInMicroseconds();
    double measureTime(double start, double end);
};

#endif