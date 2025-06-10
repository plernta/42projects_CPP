#include "Cat.hpp"

Cat::Cat()
{
    std::cout << BLACK << "Default constructor called for Cat" << RESET << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat &other)
{
    std::cout << BLACK << "Copy constructor called for Cat" << RESET << std::endl;
    _type = other._type;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << BLACK << "Assignment operator called for Cat" << RESET << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << BLACK << "Destructor called for Cat" << RESET << std::endl;
}

void Cat::makeSound() const
{
    std::cout << this->_type << ": Meow! Meow!" << std::endl;
}