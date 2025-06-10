#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << BLACK << "Default constructor called for WrongCat" << RESET << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other)
{
    std::cout << BLACK << "Copy constructor called for WrongCat" << RESET << std::endl;
    _type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    std::cout << BLACK << "Assignment operator called for WrongCat" << RESET << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << BLACK << "Destructor called for WrongCat" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << this->_type << ": Meow_WRONG! Meow_WRONG!" << std::endl;
}