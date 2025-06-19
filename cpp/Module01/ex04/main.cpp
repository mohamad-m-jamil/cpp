/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:16:43 by mjamil            #+#    #+#             */
/*   Updated: 2025/06/18 15:16:43 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int ac, char **av)
{
    std::ifstream infile(av[1]);

    if(ac == 4)
    {
        if(std::string(av[2]).empty())
        {
            std::cerr << "Error: s1 (string to replace) cannot be empty." << std::endl;
            return 1;
        }
        if(!infile)
        {
            std::cerr << "Error: Cannot open input file." << std::endl;
            return 1;
        }
        std::stringstream buff;
        buff << infile.rdbuf();
        std::string content = buff.str();
        infile.close();

        std::string res;
        std::string s1 = av[2];
        std::string s2 = av[3];

        size_t pos = 0;
        size_t found;

        while ((found = content.find(s1, pos)) != std::string::npos)
        {
            res += content.substr(pos, found - pos);
            res += s2;
            pos = found + s1.length();
        }
        res += content.substr(pos);
        std::ofstream outfile((std::string(av[1]) + ".replace").c_str());
        if (!outfile)
        {
            std::cerr << "Error: Cannot create output file." << std::endl;
            return 1;
        }
        outfile << res;
        outfile.close();
    }
    else
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    return (0);
}