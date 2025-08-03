/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:27:00 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/20 15:10:17 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) {
    std::cout << std::fixed << std::setprecision(1);

    // Handle pseudo literals
    if (literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff") {
        
        std::string floatVal;
        std::string doubleVal;

        if (literal[literal.length() - 1] == 'f')
        {
            floatVal = literal;
            doubleVal = literal.substr(0, literal.length() - 1);
        }
        else
        {
            floatVal = literal + "f";
            doubleVal = literal;
        }

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << floatVal << std::endl;
        std::cout << "double: " << doubleVal << std::endl;
        return;
    }

    // Handle single char (like 'a')
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char c = literal[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);

        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    // Try int
    {
        std::istringstream iss(literal);
        int i;
        char extra;
        if ((iss >> i) && !(iss >> extra))
        {
            char c = static_cast<char>(i);
            float f = static_cast<float>(i);
            double d = static_cast<double>(i);

            if (i >= 32 && i <= 126)
                std::cout << "char: '" << c << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;

            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }
    }

    // Try float
    if (literal[literal.length() - 1] == 'f')
    {
        std::string floatLiteral = literal.substr(0, literal.length() - 1);
        std::istringstream iss(floatLiteral);
        float f;
        char extra;
        if ((iss >> f) && !(iss >> extra))
        {
            int i = static_cast<int>(f);
            char c = static_cast<char>(f);
            double d = static_cast<double>(f);

            if (std::isnan(f) || std::isinf(f))
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
            }
            else
            {
                if (i >= 32 && i <= 126)
                    std::cout << "char: '" << c << "'" << std::endl;
                else
                    std::cout << "char: Non displayable" << std::endl;

                std::cout << "int: " << i << std::endl;
            }

            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }
    }

    // Try double
    {
        std::istringstream iss(literal);
        double d;
        char extra;
        if ((iss >> d) && !(iss >> extra))
        {
            int i = static_cast<int>(d);
            char c = static_cast<char>(d);
            float f = static_cast<float>(d);

            if (std::isnan(d) || std::isinf(d))
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
            }
            else
            {
                if (i >= 32 && i <= 126)
                    std::cout << "char: '" << c << "'" << std::endl;
                else
                    std::cout << "char: Non displayable" << std::endl;

                std::cout << "int: " << i << std::endl;
            }

            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }
    }

    // If everything failed
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}