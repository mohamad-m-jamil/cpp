/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:31:53 by mjamil            #+#    #+#             */
/*   Updated: 2025/09/14 14:19:07 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    this->data = other.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        this->data = other.data;
    return *this;
}


BitcoinExchange::~BitcoinExchange() {}

// Load database from data.csv
void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    if (!std::getline(file, line)) return;
    size_t lineno = 1;
    while (std::getline(file, line))
    {
        ++lineno;
        if (!line.empty() && line[line.size() - 1] == '\r')line.erase(line.size() - 1);
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string date, value;
        if (!std::getline(ss, date, ',') || !std::getline(ss, value)) {
            std::cerr << "Warning: invalid CSV format at line " << lineno << ": " << line << "\n";
            continue;
        }

        date  = trim(date);
        value = trim(value);

        std::istringstream iss(value);
        float rate;
        if (!(iss >> rate)) {
            std::cerr << "Warning: invalid number at line " << lineno << ": " << value << "\n";
            continue;
        }
        iss >> std::ws;
        if (!iss.eof())
        {
            std::cerr << "Warning: trailing garbage at line " << lineno << ": " << value << "\n";
            continue;
        }

        data[date] = rate;
    }
}



// Get the closest date before or equal to the given date
float BitcoinExchange::getRateForDate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = data.lower_bound(date);
    if (it == data.end() || it->first != date)
    {
        if (it == data.begin())
            throw std::runtime_error("Error: no earlier date found in database.");
        --it;
    }
    return it->second;
}

// Helper function to trim strings
std::string BitcoinExchange::trim(const std::string &str) const
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    std::istringstream ssYear(date.substr(0, 4));
    std::istringstream ssMonth(date.substr(5, 2));
    std::istringstream ssDay(date.substr(8, 2));

    if (!(ssYear >> year) || !(ssMonth >> month) || !(ssDay >> day))
        return false;

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30,
                             31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year))
        daysInMonth[2] = 29;

    if (day < 1 || day > daysInMonth[month])
        return false;

    return true;
}

// Process input file
void BitcoinExchange::processInput(const std::string &filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open input file.");

    std::string line;
    if(getline(file, line))
    {
        if (line != "date | value")
            throw std::runtime_error("Warning: unexpected header format: " + line);
    }
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = trim(date);
        valueStr = trim(valueStr);
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::istringstream iss(valueStr);
        float value;
        if (!(iss >> value))
        {
            std::cerr << "Error: invalid number => " << valueStr << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        try {
            float rate = getRateForDate(date);
            float result = rate * value;
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

