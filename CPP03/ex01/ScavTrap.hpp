#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();                                 // Default constructor
        ScavTrap(const std::string& name);          // Constructor with name
        ScavTrap(const ScavTrap& other);            // Copy constructor
        ScavTrap& operator=(const ScavTrap& other); // Copy assignment operator
        ~ScavTrap();                                // Destructor

        void guardGate();
};

#endif


