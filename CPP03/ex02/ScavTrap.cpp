#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << BLACK << "Default constructor called for ScavTrap" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << BLACK << "Destructor called for ScavTrap " << RESET << this->_name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << BLACK << "Constructor called for ScavTrap " << this->_name << RESET << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << BLACK << "Copy constructor called for ScavTrap" << RESET << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << BLACK << "Copy assignment operator called for ScavTrap" << RESET << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << this->_name << " is now in Gate keeper mode." << std::endl;
}