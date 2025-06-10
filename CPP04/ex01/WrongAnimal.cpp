#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << BLACK << "Default constructor called for WrongAnimal" << RESET << std::endl;
    _type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type)
{
    std::cout << BLACK << "Constructor with typed called for WrongAnimal" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << BLACK << "Copy constructor called for WrongAnimal" << RESET << std::endl;
    _type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << BLACK << "Assignment operator called for WrongAnimal" << RESET << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << BLACK << "Destructor called for WrongAnimal" << RESET << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << this->_type << ": WRONG WRONG" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->_type;
}