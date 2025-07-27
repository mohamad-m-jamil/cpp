/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:28:42 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/17 14:28:42 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int i = 0;
    int N = 4;
    Zombie* ok = zombieHorde(N, "Zombieland: ");
    while(i < N)
    {
        ok[i].announce();
        i++;
    }
    delete[] ok;
    return(0);
}