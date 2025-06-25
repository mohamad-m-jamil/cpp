/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 05:39:27 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/24 05:39:27 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    int i = 0;
    std::cout << "Brain constructor called" << std::endl;
    while(i < 100)
    {
        ideas[i] = "";
        i++;
    }
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    int i = 0;
    std::cout << "Brain copy constructor called" << std::endl;
    while(i < 100)
    {
        ideas[i] = other.ideas[i];
        i++;
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;

    if(this != &other)
    {
        int i = 0;
        while(i < 100)
        {
            ideas[i] = other.ideas[i];
            i++;
        }
    }
    return *this;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}