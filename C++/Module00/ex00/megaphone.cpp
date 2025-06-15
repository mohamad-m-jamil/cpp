/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:23:15 by hsarraj           #+#    #+#             */
/*   Updated: 2024/12/17 13:17:50 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
	else
	{
		for (int i = 0; i < ac; i++)
		{
			for (int j = 0; av[i][j] != '\0'; j++)
				av[i][j] = (char)toupper(av[i][j]);
			std::cout << av[i];
			if (av[i] != NULL)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}