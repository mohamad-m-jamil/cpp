/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:52:36 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/21 14:41:02 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

//We use templates so that we can write one single function 
//(like swap, min, or max) that works with different types

template  <typename T>
void swap (T& a, T&b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template  <typename T>
T min(const T& a, const T& b)
{
    if (a < b)
        return a;
    else
        return b;
}

template  <typename T>
T max(const T& a, const T& b)
{
    if (a > b)
        return a;
    else
        return b;
}

#endif