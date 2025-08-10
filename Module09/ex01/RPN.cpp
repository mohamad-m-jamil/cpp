/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 22:47:48 by mjamil            #+#    #+#             */
/*   Updated: 2025/08/10 22:47:48 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    this->operands = other.operands;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->operands = other.operands;
    return *this;
}

RPN::~RPN() {}

float  RPN::evaluate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;
    while(iss >> token)
    {
        if(token.size() == 1 && isOperator(token[0]))
        {
            if(operands.size() < 2)
                throw std::runtime_error("Error: not enough operands.");
            float b = operands.top();
            operands.pop();
            float a = operands.top();
            operands.pop();
            float result = applyOperation(a, b, token[0]);
            operands.push(result);
        }
        else
        {
            std::istringstream tokenStream(token);
            float value;
            if (!(tokenStream >> value))
                throw std::runtime_error("Error: invalid token '" + token + "'.");
            operands.push(value);
        }
    }
    if (operands.size() != 1)
        throw std::runtime_error("Error: invalid expression.");
    return operands.top();

}

float RPN::applyOperation(float a, float b, char op)
{
    if(op == '+')
        return a + b;
    else if(op == '-')
        return a - b;
    else if(op == '*')
        return a * b;
    else if(op == '/')
    {
        if(b == 0)
            throw std::runtime_error("Error: division by zero.");
        return a / b;
    }
    throw std::runtime_error("Error: invalid operator.");
}

bool RPN::isOperator(char c) const
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}