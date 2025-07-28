/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:08:15 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/26 20:08:15 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        
        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end);
};

#include "Span.tpp"

#endif