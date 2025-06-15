#include "../includes/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructed\n";
}
Brain::~Brain()
{
    std::cout << "Brain destructed\n";
}
Brain::Brain(const Brain& other)
{
    std::cout << "Brain copied\n";
    for(int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
}
Brain& Brain::operator=(const Brain& other)
{
    if(this != &other)
    {
        for(int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    std::cout << "Brain assigned\n";
    return *this;
}
void Brain::setIdea(int index, const std::string& idea)
{
    if(index >= 0 && index < 100)
        ideas[index] = idea;
}
std::string Brain::getIdea(int index) const
{
    if(index >= 0 && index < 100)
        return ideas[index];
    return "";
}