#include "Cat.hpp"

// ---------The first part of code is the wrong version of Shallow copy ---------
// ******************* For Educational purpose only. *******************
/*
Cat::Cat()
{
    std::cout << BLACK << "Default constructor called for Cat" << RESET << std::endl;
    _type = "Cat";
   _brain = new Brain(); 
}

Cat::Cat(const Cat &other)
{
    std::cout << BLACK << "Copy constructor called for Cat" << RESET << std::endl;
    _type = other._type;
    _brain = other._brain; // Shallow copy
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << BLACK << "Assignment operator called for Cat" << RESET << std::endl;
    if (this != &other)
    {
        _type = other._type;
        _brain = other._brain; // Shallow copy
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << BLACK << "Destructor called for Cat" << RESET << std::endl;
}

void Cat::makeSound() const
{
    std::cout << this->_type << ": Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return _brain;
}
*/

// ---------The following code is the correct version for Deep copy ---------

Cat::Cat()
{
    std::cout << BLACK << "Default constructor called for Cat" << RESET << std::endl;
    _type = "Cat";
   _brain = new Brain(); 
}

Cat::Cat(const Cat &other)
{
    std::cout << BLACK << "Copy constructor called for Cat" << RESET << std::endl;
    _type = other._type;
    _brain = new Brain(*other._brain); // Deep copy
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << BLACK << "Assignment operator called for Cat" << RESET << std::endl;
    if (this != &other)
    {
        _type = other._type;
        delete _brain; // Free the old brain
        _brain = new Brain(*other._brain); // Deep copy - Create a new brain
    }
    return *this;
}

Cat::~Cat()
{
    delete _brain; // Free the brain
    std::cout << BLACK << "Destructor called for Cat" << RESET << std::endl;
}

void Cat::makeSound() const
{
    std::cout << this->_type << ": Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return _brain;
}

