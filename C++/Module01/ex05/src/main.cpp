#include "../include/Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Testing DEBUG:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nTesting INFO:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nTesting WARNING:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nTesting ERROR:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nTesting UNKNOWN:" << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}
