#include "Zombie.hpp"
#include <iostream>

void    Zombie::setName(std::string name)
{
    this->_name = name;
}

std::string Zombie::getName(void) const
{
    return this->_name;
}

Zombie::Zombie()
{
    std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie destructor called" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->getName() << ": BraiiiiiiinnnnzzzZ..." << std::endl;
}