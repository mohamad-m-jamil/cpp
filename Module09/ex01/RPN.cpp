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

float RPN::evaluate(const std::string& expression)
{
    // Create a string stream from the input expression to read token by token
    std::istringstream iss(expression);
    std::string token;

    // Loop through each token separated by spaces
    while(iss >> token)
    {
        // Check if the token is a single-character operator (+, -, *, /)
        if(token.size() == 1 && isOperator(token[0]))
        {
            // Ensure there are at least two operands on the stack
            if(operands.size() < 2)
                throw std::runtime_error("Error: not enough operands.");

            // Pop the last two operands from the stack
            float b = operands.top();  // Second operand (top of the stack)
            operands.pop();
            float a = operands.top();  // First operand
            operands.pop();

            // Apply the operator to the two operands
            float result = applyOperation(a, b, token[0]);

            // Push the result back onto the stack
            operands.push(result);
        }
        else
        {
            // Token is assumed to be a number
            std::istringstream tokenStream(token);
            float value;

            // Try converting the token to a float
            if (!(tokenStream >> value))
                throw std::runtime_error("Error: invalid token '" + token + "'.");

            // Push the number onto the stack
            operands.push(value);
        }
    }

    // After processing all tokens, there should be exactly one number left on the stack
    if (operands.size() != 1)
        throw std::runtime_error("Error: invalid expression.");

    // Return the final result
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