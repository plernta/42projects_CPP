#include "Zombie.hpp"

Zombie::Zombie(std::string name)
    : _name(name)
{
    _name = name;
    std::cout << GREEN << this->_name << " is constructed" << RESET << std::endl;
}

Zombie::~Zombie()
{
    std::cout << RED << this->_name << " is destructed" << RESET << std::endl;
}

void Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}