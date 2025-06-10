#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << BLACK << "Default constructor called for Animal " << RESET << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
    std::cout << BLACK << "Constructor with type called for Animal " << RESET << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
    std::cout << BLACK << "Copy constructor called for Animal" << RESET << std::endl;
}

Animal::~Animal()
{
    std::cout << BLACK << "Destructor called for Animal" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << BLACK << "Assignment operator called for Animal" << RESET << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << this->_type << ": I am animal, but I don't know who I am; I don't know which sound I should make. -\"-" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}