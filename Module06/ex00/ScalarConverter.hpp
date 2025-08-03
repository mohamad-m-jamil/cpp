/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:27:08 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/27 15:43:26 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter&);
        ScalarConverter( const ScalarConverter&);
        ~ScalarConverter();
    public:
        static void convert(const std::string& literal);
};

#endif