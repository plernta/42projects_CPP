#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type): _weapon(weapon_type)
{
    std::cout << BLACK << "Weapon constructor called" << RESET << std::endl;
}

Weapon::~Weapon()
{
    std::cout << BLACK << "Weapon destructor called" << RESET << std::endl;
}

void Weapon::setType(std::string weapon_type)
{
    this->_weapon = weapon_type;
}

std::string& Weapon::getType()
{
    return (this->_weapon);   
};
