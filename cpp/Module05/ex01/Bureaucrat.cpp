/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 08:52:18 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/03 09:49:17 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{   
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

Bureaucrat::~Bureaucrat(){}

void Bureaucrat::incrementGrade()
{
    if(this->grade < 2)
        throw GradeTooHighException();
    else
        this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    if(this->grade > 149)
        throw GradeTooLowException();
    else
        this->grade += 1;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) , grade(other.grade)
{
    
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
        this->grade = other.grade;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

void Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);  // We try to sign the form
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
