#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << BLACK << "Default constructor called for FragTrap" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << BLACK << "Destructor called for FragTrap " << RESET << this->_name << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << BLACK << "Constructor called for FragTrap " << this->_name << RESET << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
{
    std::cout << BLACK << "Copy constructor called for FragTrap" << RESET << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << BLACK << "Copy assignment operator called for FragTrap" << RESET << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << this->_name << " is requesting a high five!" << std::endl;
}