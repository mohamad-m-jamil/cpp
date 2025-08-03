/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 08:52:30 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/07 08:47:58 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try {
        Bureaucrat highRank("Alice", 1);
        Bureaucrat midRank("Bob", 40);
        Bureaucrat lowRank("Charlie", 150);

        // Test ShrubberyCreationForm
        ShrubberyCreationForm shrub("home");
        highRank.signForm(shrub);
        highRank.executeForm(shrub);

        std::cout << "\n";

        // Test RobotomyRequestForm
        RobotomyRequestForm robo("Bender");
        midRank.signForm(robo);
        midRank.executeForm(robo);

        std::cout << "\n";

        // Test PresidentialPardonForm
        PresidentialPardonForm pardon("Ford Prefect");
        highRank.signForm(pardon);
        highRank.executeForm(pardon);

    } catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
