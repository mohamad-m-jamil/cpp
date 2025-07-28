/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:08:10 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/26 20:08:10 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0)
{}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{}

Span::Span(unsigned int n) : _maxSize(n)
{}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int n)
{
    if(_numbers.size() >= _maxSize)
    {
        throw std::runtime_error("Cannot add more numbers: Span is full.");
    }
    _numbers.push_back(n);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough elements to find a span.");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::abs(sorted[1] - sorted[0]);
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int diff = std::abs(sorted[i + 1] - sorted[i]);
        if (diff < minSpan)
            minSpan = diff;
    }

    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough elements to find a span.");
    int minn = _numbers[0];
    int maxn = _numbers[0];
    for (size_t i = 1; i < _numbers.size(); ++i)
    {
        if (_numbers[i] < minn)
            minn = _numbers[i];
        if (_numbers[i] > maxn)
            maxn = _numbers[i];
    }
    int res = maxn - minn;
    return res;
}
