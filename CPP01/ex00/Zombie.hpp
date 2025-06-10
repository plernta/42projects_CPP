#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie( std::string name );
        ~Zombie();
        void announce( void );
};

#endif