/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 08:52:30 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/07 07:49:41 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 2);
        Form taxForm("TaxForm", 2, 10);

        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);  // Bob tries to sign TaxForm
        std::cout << taxForm << std::endl;

        bob.incrementGrade();  // Bob goes from 2 to 1 (highest)
        std::cout << "After increment: " << bob << std::endl;

        Form secretForm("SecretForm", 1, 5);
        bob.signForm(secretForm);
        std::cout << secretForm << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat alice("Alice", 149);
        Form difficultForm("DifficultForm", 150, 100);

        std::cout << alice << std::endl;
        std::cout << difficultForm << std::endl;

        alice.signForm(difficultForm);  // Alice tries to sign

        alice.decrementGrade();  // Alice goes from 149 to 150 (lowest)
        std::cout << "After decrement: " << alice << std::endl;

        Form impossibleForm("ImpossibleForm", 149, 50);
        alice.signForm(impossibleForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
