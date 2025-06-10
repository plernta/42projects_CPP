#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#define BLACK "\033[30m"
#define RESET "\033[0m"

class Animal
{
protected:
    std::string _type;
public:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();  

    virtual void makeSound() const = 0; // Pure virtual function
    std::string getType() const;
};

#endif