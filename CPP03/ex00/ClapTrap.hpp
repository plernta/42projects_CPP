#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <sstream>

#define BLACK "\033[30m"
#define RESET "\033[0m"
#define BLUE "\033[34m"

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
    public:
        ClapTrap();                                 // Default constructor
        ClapTrap(const std::string& name);          // Constructor with name
        ClapTrap(const ClapTrap& other);            // Copy constructor
        ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
        ~ClapTrap();                                // Destructor

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
        unsigned int getHitPoints() const;
        unsigned int getEnergyPoints() const;
        unsigned int getAttackDamage() const;

        std::string status() const;
};

#endif