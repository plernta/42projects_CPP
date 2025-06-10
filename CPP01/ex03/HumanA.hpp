#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

#define BLACK "\033[30m"
#define RESET "\033[0m"

class HumanA
{
private:
    std::string _name;
    Weapon&     _weapon;

public:
    HumanA(std::string name, Weapon &weapon);;
    ~HumanA();
    void    attack();
};

#endif