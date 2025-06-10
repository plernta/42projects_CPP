#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
    std::cout << BLACK << "HumanA constructor called" << RESET << std::endl;
}

HumanA::~HumanA()
{
    std::cout << BLACK << "HumanA destructor called" << RESET << std::endl;
}

void HumanA::attack()
{
    std::cout << this->_name << " attacks with " << this->_weapon.getType() << std::endl;
}