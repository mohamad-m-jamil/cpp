#include <iostream>
#include <fstream>
#include <sstream>

int main(int ac, char **av)
{
    // Step 1: Check for correct number of arguments
    if (ac != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = av[1]; 
    std::string s1 = av[2];
    std::string s2 = av[3];

    // Step 1.1: Validate that s1 is not empty (to avoid infinite loop in replacement)
    if (s1.empty())
    {
        std::cerr << "Error: s1 (string to replace) cannot be empty." << std::endl;
        return 1;
    }

    // Step 2: Read file content into a string
    std::ifstream inputFile(filename.c_str());
    if (!inputFile)
    {
        std::cerr << "Error: Failed to open file '" << filename << "'" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();
    inputFile.close();

    // Step 3: Replace all occurrences of s1 with s2
    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result.append(content.substr(pos, found - pos));
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(content.substr(pos));

    // Step 4: Write the modified content to a new file with ".replace" suffix
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile)
    {
        std::cerr << "Error: Failed to create output file." << std::endl;
        return 1;
    }

    outputFile << result;
    outputFile.close();

    std::cout << "Replacement complete! Output written to: " << filename + ".replace" << std::endl;
    
    return 0;
}
