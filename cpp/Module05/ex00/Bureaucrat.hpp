/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:29:44 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/30 08:59:53 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        std::string getName() const;
        int getGrade();
        ~Bureaucrat();
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception
        {
            const char* what() const noexcept override;
        };

        class GradeTooLowException : public std::exception
        {
            const char* what() const noexcept override;
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif