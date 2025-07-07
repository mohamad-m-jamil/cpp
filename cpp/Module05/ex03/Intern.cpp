/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:20:31 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/07 15:42:33 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string forms[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[])(const std::string&) = {
        [](const std::string& target) -> AForm* { return new ShrubberyCreationForm(target); },
        [](const std::string& target) -> AForm* { return new RobotomyRequestForm(target); },
        [](const std::string& target) -> AForm* { return new PresidentialPardonForm(target); }
    };

    for (int i = 0; i < 3; ++i)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    std::cerr << "Error: Form \"" << formName << "\" not found." << std::endl;
    return NULL;
}