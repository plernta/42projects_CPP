#include "Dog.hpp"

Dog::Dog()
{
    std::cout << BLACK << "Default constructor called for Dog" << RESET << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog &other)
{
    std::cout << BLACK << "Copy constructor called for Dog" << RESET << std::endl;
    _type = other._type;
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << BLACK << "Assignment operator called for Dog" << RESET << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << BLACK << "Destructor called for Dog" << RESET << std::endl;
}

void Dog::makeSound() const
{
    std::cout << this->_type << ": Woof! Woof!" << std::endl;
}