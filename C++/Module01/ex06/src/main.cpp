#include "../include/Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <level>\n";
        return 1;
    }

    std::string level = argv[1];
    Harl harl;
    int levelIndex = -1;

    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            levelIndex = i;
            break;
        }
    }

    switch (levelIndex) {
        case 0:
            harl.complain("DEBUG");
            // fall through
        case 1:
            harl.complain("INFO");
            // fall through
        case 2:
            harl.complain("WARNING");
            // fall through
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }

    return 0;
}
