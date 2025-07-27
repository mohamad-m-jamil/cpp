/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:55:37 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/18 12:55:37 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main ()
{
    std::string i = "HI THIS IS BRAIN";
    std::string* stringPTR = &i;
    std::string& stringREF = i;

    std::cout << "Address of string variable:   " << &i << std::endl;
    std::cout << "Address held by stringPTR:    " << stringPTR << std::endl;
    std::cout << "Address held by stringREF:    " << &stringREF << std::endl;

    std::cout << "Value of string variable:     " << i << std::endl;
    std::cout << "Value pointed to by stringPTR:" << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF:" << stringREF << std::endl;

    return 0;
}