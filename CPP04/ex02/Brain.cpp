#include "Brain.hpp"

Brain::Brain()
{
    std::cout << BLACK << "Default constructor called for Brain" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << BLACK << "Copy constructor called for Brain" << RESET << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain &other)
{
    std::cout << BLACK << "Assignment operator called for Brain" << RESET << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << BLACK << "Destructor called for Brain" << RESET << std::endl;
    // No need to delete ideas as they are not dynamically allocated
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
    {
        this->ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
    {
        return this->ideas[index];
    }
    return 0;
}