/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:29:38 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/28 12:30:40 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"
#include <iterator>
#include <stdexcept>

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end)
{
    size_t distance = std::distance(begin, end);
    if (_numbers.size() + distance > _maxSize)
        throw std::runtime_error("Not enough space to add all numbers.");

    _numbers.insert(_numbers.end(), begin, end);
}


#endif
