#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
    std::cout << BLACK << "HumanB constructor called" << RESET << std::endl;
}

HumanB::~HumanB()
{
    std::cout << BLACK << "HumanB destructor called" << RESET << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}

void    HumanB::attack()
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon" << std::endl;
}