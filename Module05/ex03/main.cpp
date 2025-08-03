/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 08:52:30 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/07 15:46:23 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat bob("Bob", 1); // High-level bureaucrat to sign & execute

    AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
    AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    AForm* form4 = someRandomIntern.makeForm("unknown form", "NoTarget");

    std::cout << std::endl;

    if (form1)
    {
        bob.signForm(*form1);
        bob.executeForm(*form1);
        delete form1;
    }

    std::cout << std::endl;

    if (form2)
    {
        bob.signForm(*form2);
        bob.executeForm(*form2);
        delete form2;
    }

    std::cout << std::endl;

    if (form3)
    {
        bob.signForm(*form3);
        bob.executeForm(*form3);
        delete form3;
    }

    std::cout << std::endl;

    if (form4)
    {
        // should not happen
        delete form4;
    }

    return 0;
}
