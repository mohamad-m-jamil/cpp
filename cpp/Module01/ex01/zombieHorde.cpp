/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:28:36 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/17 14:28:36 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if(N <= 0)
        return 0;
    int i = 0;
    Zombie* horde = new Zombie[N];
    while(i < N)
    {
        horde[i].setName(name);
        i++;
    }
    return horde;
}
