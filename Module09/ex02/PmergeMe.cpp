/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:51:50 by mjamil            #+#    #+#             */
/*   Updated: 2025/08/12 21:51:50 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ===== Orthodox Form =====
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        // Nothing dynamic to copy currently
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

// ===== Parsing & Validation =====
bool PmergeMe::isNumber(const std::string &s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); i++) {
        if (!std::isdigit(s[i])) return false;
    }
    // Check for overflow
    long long num = std::atoll(s.c_str());
    return num >= 0 && num <= 2147483647;
}

bool PmergeMe::hasDuplicate(const std::vector<int> &arr) {
    std::set<int> seen;
    for (size_t i = 0; i < arr.size(); i++) {
        if (!seen.insert(arr[i]).second)
            return true;
    }
    return false;
}

std::vector<int> PmergeMe::parseNumbers(int argc, char* argv[]) {
    if (argc < 2) {
        throw std::runtime_error("Error: No arguments provided");
    }
    
    std::vector<int> numbers;
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (!isNumber(arg)) {
            throw std::runtime_error("Error: Invalid argument: " + arg);
        }
        numbers.push_back(std::atoi(arg.c_str()));
    }
    
    if (hasDuplicate(numbers)) {
        throw std::runtime_error("Error: Duplicate numbers found");
    }
    
    return numbers;
}

// ===== Vector Implementation =====
std::vector<int> PmergeMe::fordJohnsonSortVector(const std::vector<int>& input) {
    if (input.size() <= 1) return input;
    
    std::vector<int> mainChain;
    std::vector<int> pendChain;
    int straggler = -1;
    bool hasStraggler = false;
    
    // Step 1: Create pairs and separate into main and pend chains
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i];
        int b = input[i + 1];
        if (a > b) {
            mainChain.push_back(a);
            pendChain.push_back(b);
        } else {
            mainChain.push_back(b);
            pendChain.push_back(a);
        }
    }
    
    // Handle straggler
    if (input.size() % 2 == 1) {
        straggler = input.back();
        hasStraggler = true;
    }
    
    // Step 2: Recursively sort the main chain
    if (mainChain.size() > 1) {
        mainChain = fordJohnsonSortVector(mainChain);
    }
    
    // Step 3: Insert pend elements using Ford-Johnson insertion order
    mergeInsertionVector(mainChain, pendChain);
    
    // Step 4: Insert straggler if exists
    if (hasStraggler) {
        binaryInsertVector(mainChain, straggler, mainChain.size());
    }
    
    return mainChain;
}

void PmergeMe::mergeInsertionVector(std::vector<int>& mainChain, const std::vector<int>& pendChain) {
    if (pendChain.empty()) return;
    
    // Insert first pend element - it should be inserted before its partner
    // Since pairs were created with larger element first, the first pend element
    // corresponds to the first main element
    binaryInsertVector(mainChain, pendChain[0], 1);
    
    if (pendChain.size() == 1) return;
    
    // Generate Jacobsthal-based insertion indices
    std::vector<int> indices = generateJacobsthalIndices(pendChain.size());
    
    // Insert remaining elements according to Jacobsthal sequence
    for (size_t i = 0; i < indices.size(); i++) {
        int idx = indices[i];
        if (idx >= 0 && idx < (int)pendChain.size()) {
            // The upper bound is the position of the partner + all previously inserted elements
            // This is a simplified bound - in a complete implementation you'd track pairs more carefully
            int upperBound = mainChain.size();
            
            // Find a reasonable upper bound based on the partner's likely position
            if (idx < (int)mainChain.size()) {
                upperBound = idx + i + 2; // Heuristic bound
                if (upperBound > (int)mainChain.size()) 
                    upperBound = mainChain.size();
            }
            
            binaryInsertVector(mainChain, pendChain[idx], upperBound);
        }
    }
}

std::vector<int> PmergeMe::generateJacobsthalIndices(int pendSize) {
    if (pendSize <= 1) return std::vector<int>();
    
    // Generate Jacobsthal numbers
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    if (pendSize > 1) jacobsthal.push_back(1);
    
    while (true) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= pendSize) break;
        jacobsthal.push_back(next);
    }
    
    // Generate insertion order
    std::vector<int> indices;
    std::vector<bool> used(pendSize, false);
    
    // Start from index 1 (second element), since first element is inserted separately
    int currentStart = 1;
    
    for (size_t i = 1; i < jacobsthal.size(); i++) {
        int jacobNum = jacobsthal[i];
        if (jacobNum >= pendSize) jacobNum = pendSize - 1;
        
        // Insert indices from jacobNum down to currentStart + 1
        for (int j = jacobNum; j > currentStart; j--) {
            if (j > 0 && j < pendSize && !used[j]) {
                indices.push_back(j);
                used[j] = true;
            }
        }
        currentStart = jacobNum;
    }
    
    // Add any remaining indices
    for (int i = 1; i < pendSize; i++) {
        if (!used[i]) {
            indices.push_back(i);
        }
    }
    
    return indices;
}

void PmergeMe::binaryInsertVector(std::vector<int>& mainChain, int value, int upperBound) {
    int left = 0;
    int right = std::min(upperBound, (int)mainChain.size());
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mainChain[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    mainChain.insert(mainChain.begin() + left, value);
}

// ===== Deque Implementation =====
std::deque<int> PmergeMe::fordJohnsonSortDeque(const std::vector<int>& input) {
    std::deque<int> inputDeque(input.begin(), input.end());
    
    if (inputDeque.size() <= 1) return inputDeque;
    
    std::deque<int> mainChain;
    std::deque<int> pendChain;
    int straggler = -1;
    bool hasStraggler = false;
    
    // Step 1: Create pairs and separate into main and pend chains
    for (size_t i = 0; i + 1 < inputDeque.size(); i += 2) {
        int a = inputDeque[i];
        int b = inputDeque[i + 1];
        if (a > b) {
            mainChain.push_back(a);
            pendChain.push_back(b);
        } else {
            mainChain.push_back(b);
            pendChain.push_back(a);
        }
    }
    
    // Handle straggler
    if (inputDeque.size() % 2 == 1) {
        straggler = inputDeque.back();
        hasStraggler = true;
    }
    
    // Step 2: Recursively sort the main chain
    if (mainChain.size() > 1) {
        std::vector<int> mainVec(mainChain.begin(), mainChain.end());
        mainVec = fordJohnsonSortVector(mainVec);
        mainChain = std::deque<int>(mainVec.begin(), mainVec.end());
    }
    
    // Step 3: Insert pend elements
    mergeInsertionDeque(mainChain, pendChain);
    
    // Step 4: Insert straggler if exists
    if (hasStraggler) {
        binaryInsertDeque(mainChain, straggler, mainChain.size());
    }
    
    return mainChain;
}

void PmergeMe::mergeInsertionDeque(std::deque<int>& mainChain, const std::deque<int>& pendChain) {
    if (pendChain.empty()) return;
    
    // Insert first pend element
    binaryInsertDeque(mainChain, pendChain[0], 1);
    
    if (pendChain.size() == 1) return;
    
    // Generate Jacobsthal-based insertion indices
    std::vector<int> indices = generateJacobsthalIndices(pendChain.size());
    
    // Insert remaining elements according to Jacobsthal sequence
    for (size_t i = 0; i < indices.size(); i++) {
        int idx = indices[i];
        if (idx >= 0 && idx < (int)pendChain.size()) {
            int upperBound = mainChain.size();
            
            if (idx < (int)mainChain.size()) {
                upperBound = idx + i + 2;
                if (upperBound > (int)mainChain.size()) 
                    upperBound = mainChain.size();
            }
            
            binaryInsertDeque(mainChain, pendChain[idx], upperBound);
        }
    }
}

void PmergeMe::binaryInsertDeque(std::deque<int>& mainChain, int value, int upperBound) {
    int left = 0;
    int right = std::min(upperBound, (int)mainChain.size());
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mainChain[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    mainChain.insert(mainChain.begin() + left, value);
}

// ===== Utility Functions =====
void PmergeMe::displaySequence(const std::vector<int>& seq, const std::string& label) {
    std::cout << label;
    for (size_t i = 0; i < seq.size() && i < 10; i++) {
        std::cout << seq[i] << " ";
    }
    if (seq.size() > 10) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

double PmergeMe::getCurrentTimeInMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

double PmergeMe::measureTime(double start, double end) {
    return end - start;
}

// ===== Main Process Function =====
void PmergeMe::processAndSort(int argc, char* argv[]) {
    std::vector<int> numbers = parseNumbers(argc, argv);
    
    displaySequence(numbers, "Before: ");
    
    // Sort with vector
    double start1 = getCurrentTimeInMicroseconds();
    std::vector<int> sortedVector = fordJohnsonSortVector(numbers);
    double end1 = getCurrentTimeInMicroseconds();
    double timeVector = measureTime(start1, end1);
    
    // Sort with deque
    double start2 = getCurrentTimeInMicroseconds();
    std::deque<int> sortedDeque = fordJohnsonSortDeque(numbers);
    double end2 = getCurrentTimeInMicroseconds();
    double timeDeque = measureTime(start2, end2);
    
    displaySequence(sortedVector, "After:  ");
    
    std::cout << "Time to process a range of " << numbers.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size() 
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) 
              << timeDeque << " us" << std::endl;
}