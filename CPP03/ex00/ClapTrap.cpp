#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << BLACK << "Default constructor called for ClapTrap" << RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << BLACK << "Destructor called for ClapTrap " << RESET << this->_name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << BLACK << "Constructor called for ClapTrap " << this->_name << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << BLACK << "Copy constructor called for ClapTrap" << RESET << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << BLACK << "Copy assignment operator called for ClapTrap" << RESET << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{   
    if (this->_energyPoints <= 0)
    {
        std::cout <<  this->_name << " does not have enough energy points to attack!" << std::endl;
        return;
    }
    else if (this->_hitPoints <= 0)
    {
        std::cout <<  this->_name << " does not have enough hit points to attack!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout <<  this->_name << " attacks " << target 
              << ", causing " << this->_attackDamage << " points of damage! Remaining energy points: " << this->_energyPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > this->_hitPoints)
    {
        this->_hitPoints = 0;
    }
    else
    {
        this->_hitPoints -= amount;
    }
    std::cout <<  this->_name << " was attacked with " << amount 
              << " points of damage! Remaining hit points: " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints <= 0)
    {
        std::cout <<  this->_name << " does not have enough ENERGY POINT to repair!" << std::endl;
        return;
    }
    else if (this->_hitPoints <= 0)
    {
        std::cout <<  this->_name << " does not have enough HIT POINT to repair!" << std::endl;
        return;
    }
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
    std::cout <<  this->_name << " is lucky. Deva gives a chance to boost up for " << amount 
              << " hit points! Remaining hit points: " << this->_hitPoints 
              << ", remaining energy points: " << this->_energyPoints << std::endl;
}

std::string ClapTrap::getName() const
{
    return this->_name;
}

unsigned int ClapTrap::getHitPoints() const
{
    return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return this->_attackDamage;
}

std::string ClapTrap::status() const
{
    std::ostringstream oss;
    oss << this->_name << "\n"
        << " hit points: " << this->_hitPoints << "\n"
        << " energy points: " << this->_energyPoints << "\n"
        << " attack damage: " << this->_attackDamage << "\n";
    return oss.str();
}