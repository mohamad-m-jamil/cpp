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

PmergeMe::PmergeMe() : is_recursive_call(false), vec_comparisons(0), deq_comparisons(0) {}





void PmergeMe::parseInput(char** argv)
{
    if (!argv[1])
    {
        std::cerr << "Error: No arguments provided." << std::endl;
        exit(EXIT_FAILURE);
    }
    
    int i = 1;
    while (argv[i])
    {
        
        std::string arg = argv[i];
        if (arg.empty()) {
            std::cerr << "Error: Empty argument." << std::endl;
            exit(EXIT_FAILURE);
        }
        
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!std::isdigit(arg[j]))
            {
                std::cerr << "Error: Invalid input. Only positive integers allowed." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        
        int num = std::atoi(argv[i]);
        
        if (num <= 0)
        {
            std::cerr << "Error: Only positive integers allowed." << std::endl;
            exit(EXIT_FAILURE);
        }
        
        for (size_t k = 0; k < vec_container.size(); k++)
        {
            if (vec_container[k] == num)
            {
                std::cerr << "Error: Duplicate values not allowed." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        
        vec_container.push_back(num);
        deq_container.push_back(num);
        original_input.push_back(num);
        
        i++;
    }
}




void PmergeMe::sortWithVector()
{
    // Reset comparison counter if this is the top-level call
    if (!is_recursive_call)
        vec_comparisons = 0;
    
    clock_t start = clock();

    // --- Base cases: handle very small inputs ---
    if(vec_container.size() < 2)
    {
        // Nothing to sort
        clock_t end = clock();
        vector_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000.0;
        return;
    }
    if(vec_container.size() == 2)
    {
        // One comparison to sort a pair
        if (!is_recursive_call) vec_comparisons++;
        if(vec_container[0] > vec_container[1])
            std::swap(vec_container[0], vec_container[1]);

        clock_t end = clock();
        vector_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000.0;
        return;
    }

    // ====================================================
    // 1) PAIRING ELEMENTS
    // ====================================================
    std::vector<std::pair<int,int> > pairs;
    int leftover = -1;

    int i = 0;
    while((size_t)(i + 1) < vec_container.size())
    {
        // Count one ordering comparison per pair
        if (!is_recursive_call) vec_comparisons++;

        // Store pair as (larger, smaller)
        if(vec_container[i] > vec_container[i + 1])
            pairs.push_back(std::make_pair(vec_container[i], vec_container[i + 1]));
        else
            pairs.push_back(std::make_pair(vec_container[i + 1], vec_container[i]));
        i += 2;
    }
    // Handle odd leftover element (goes to pend_chain later)
    if(vec_container.size() % 2 != 0)
        leftover = vec_container.back();

    // ====================================================
    // 2) BUILD MAIN & PEND CHAINS
    // ====================================================
    std::vector<int> main_chain;
    std::vector<int> pend_chain;

    i = 0;
    while((size_t)i < pairs.size())
    {
        // Larger elements → main chain
        main_chain.push_back(pairs[i].first);
        // Smaller elements → pend chain
        pend_chain.push_back(pairs[i].second);
        i++;
    }
    if(leftover != -1)
        pend_chain.push_back(leftover);

    // Save original input, then set container = main_chain
    std::vector<int> original_vec = vec_container;
    vec_container = main_chain;
    
    // ====================================================
    // 3) RECURSIVE SORT ON MAIN CHAIN
    // ====================================================
    is_recursive_call = true;
    sortWithVector();    // recursive call sorts the main_chain
    is_recursive_call = false;

    std::vector<int> sorted_main = vec_container;
    vec_container = original_vec;   // restore container to original

    // If no pend elements, we are done
    if (pend_chain.empty())
    {
        vec_container = sorted_main;
        clock_t end = clock();
        vector_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000.0;
        vector_time = vector_time / 10000.0;
        return;
    }
    
    // ====================================================
    // 4) BUILD JACOBSTHAL SEQUENCE
    // ====================================================
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    if (pend_chain.size() > 1) {
        jacobsthal.push_back(1);
        
        while (jacobsthal.back() < (int)pend_chain.size())
        {
            int next = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
            jacobsthal.push_back(next);
        }
    }
    
    // ====================================================
    // 5) COMPUTE INSERTION ORDER FROM JACOBSTHAL
    // ====================================================
    std::vector<int> insertion_order;
    
    // First pend element (index 0) is special - it goes first but with optimized search
    insertion_order.push_back(0);
    
    for (size_t i = 2; i < jacobsthal.size(); i++)
    {
        int start = std::min(jacobsthal[i], (int)pend_chain.size());
        int end = jacobsthal[i-1] + 1;

        // Push indices in reverse range [end-1 .. start-1]
        int j = start - 1;
        while (j >= end - 1 && j >= 1)
        {
            insertion_order.push_back(j);
            j--;
        }
    }
    
    // ====================================================
    // 6) INSERT PEND ELEMENTS INTO MAIN CHAIN
    // ====================================================
    std::vector<int> result = sorted_main;
    
    for (size_t i = 0; i < insertion_order.size(); i++)
    {
        int pend_index = insertion_order[i];
        int element_to_insert = pend_chain[pend_index];
        
        int left = 0;
        int right = result.size();
        
        // Upper bound optimization: stop search at partner's position
        if (pend_index < (int)pairs.size())
        {
            int partner = pairs[pend_index].first;
            for (int j = 0; j < (int)result.size(); j++)
            {
                if (result[j] == partner)
                {
                    right = j + 1;
                    break;
                }
            }
        }
        
        // Standard binary search in [left,right)
        // Special case: if search space is 1 element, no comparison needed
        if (right - left <= 1)
        {
            // Insert at position 'left' without comparison
            result.insert(result.begin() + left, element_to_insert);
        }
        else
        {
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                // Count only ordering comparisons (> or <)
                if (!is_recursive_call) vec_comparisons++;
                if (result[mid] > element_to_insert)
                    right = mid;
                else
                    left = mid + 1;
            }
            
            // Insert pend element at found position
            result.insert(result.begin() + left, element_to_insert);
        }
    }
    
    vec_container = result;
    
    // ====================================================
    // END: measure elapsed time
    // ====================================================
    clock_t end = clock();
    vector_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000.0;
    vector_time = vector_time / 100000.0;
}


///////////////////////////////////////////////


void PmergeMe::sortWithDeque()
{
    if (!is_recursive_call)
        deq_comparisons = 0;
    
    clock_t start = clock();
    if(deq_container.size() < 2)
    {
        clock_t end = clock();
        deque_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000.0;
        return;
    }
    if(deq_container.size() == 2)
    {
        if (!is_recursive_call) deq_comparisons++;
        if(deq_container[0] > deq_container[1])
            std::swap(deq_container[0], deq_container[1]);
        clock_t end = clock();
        deque_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000.0;
        return;
    }
    std::deque<std::pair<int,int> > pairs;
    int leftover = -1;
    int i = 0;
    while((size_t)(i + 1) < deq_container.size())
    {
        if (!is_recursive_call) deq_comparisons++;
        if(deq_container[i] > deq_container[i + 1])
            pairs.push_back(std::make_pair(deq_container[i], deq_container[i + 1]));
        else
            pairs.push_back(std::make_pair(deq_container[i + 1], deq_container[i]));
        i += 2;
    }
    if(deq_container.size() % 2 != 0)
        leftover = deq_container.back();
    std::deque<int> main_chain;
    std::deque<int> pend_chain;
    i = 0;
    while((size_t)i < pairs.size())
    {
        main_chain.push_back(pairs[i].first);
        pend_chain.push_back(pairs[i].second);
        i++;
    }
    if(leftover != -1)
        pend_chain.push_back(leftover);
    std::deque<int> original_deq = deq_container;
    deq_container = main_chain;
    is_recursive_call = true;
    sortWithDeque();
    is_recursive_call = false;
    std::deque<int> sorted_main = deq_container;
    deq_container = original_deq;
    if (pend_chain.empty())
    {
        deq_container = sorted_main;
        clock_t end = clock();
        deque_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000.0;
        deque_time = deque_time / 10000.0;
        return;
    }
    std::deque<int> jacobsthal;
    jacobsthal.push_back(1);
    if (pend_chain.size() > 1) {
        jacobsthal.push_back(1);
        
        while (jacobsthal.back() < (int)pend_chain.size())
        {
            int next = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
            jacobsthal.push_back(next);
        }
    }
    std::deque<int> insertion_order;
    insertion_order.push_back(0);
    for (size_t i = 2; i < jacobsthal.size(); i++)
    {
        int start = std::min(jacobsthal[i], (int)pend_chain.size());
        int end = jacobsthal[i-1] + 1;
        int j = start - 1;
        while (j >= end - 1 && j >= 1)
        {
            insertion_order.push_back(j);
            j--;
        }
    }
    std::deque<int> result = sorted_main;
    for (size_t i = 0; i < insertion_order.size(); i++)
    {
        int pend_index = insertion_order[i];
        int element_to_insert = pend_chain[pend_index];
        int left = 0;
        int right = result.size();
        if (pend_index < (int)pairs.size())
        {
            int partner = pairs[pend_index].first;
            for (int j = 0; j < (int)result.size(); j++)
            {
                if (result[j] == partner)
                {
                    right = j + 1;
                    break;
                }
            }
        }
        if (right - left <= 1)
            result.insert(result.begin() + left, element_to_insert);
        else
        {
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (!is_recursive_call) deq_comparisons++;
                if (result[mid] > element_to_insert)
                    right = mid;
                else
                    left = mid + 1;
            }
            result.insert(result.begin() + left, element_to_insert);
        }
    }
    deq_container = result;
    clock_t end = clock();
    deque_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000.0;
    deque_time = deque_time / 100000.0;
}





void PmergeMe::displayResults()
{
   std::cout << "Before: ";
   for (size_t i = 0; i < original_input.size(); i++) {
       std::cout << original_input[i] << " ";
   }
   std::cout << std::endl;
   
   std::cout << "After for vec: ";
   for (size_t i = 0; i < vec_container.size(); i++) {
       std::cout << vec_container[i] << " ";
   }
   std::cout << std::endl;

   std::cout << "After for deq: ";
   for (size_t i = 0; i < deq_container.size(); i++) {
       std::cout << deq_container[i] << " ";
   }
   std::cout << std::endl;
   
   std::cout << "Time to process a range of " << vec_container.size() 
             << " elements with std::vector : " << std::fixed 
             << std::setprecision(5) << vector_time << " us" << std::endl;
             
   std::cout << "Time to process a range of " << deq_container.size() 
             << " elements with std::deque : " << std::fixed 
             << std::setprecision(5) << deque_time << " us" << std::endl;

   std::cout << "Vector comparisons: " << vec_comparisons << std::endl;
   std::cout << "Deque comparisons: " << deq_comparisons << std::endl;
}