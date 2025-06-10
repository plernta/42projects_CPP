#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

#define BLACK "\033[30m"
#define RESET "\033[0m"

class Weapon
{
private:
    std::string _weapon;
public:
    Weapon(std::string weapon_type);
    ~Weapon();
    void            setType(std::string weapon_type);
    std::string&    getType();
};
#endif