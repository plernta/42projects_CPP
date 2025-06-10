#include "Dog.hpp"

Dog::Dog()
{
    std::cout << BLACK << "Default constructor called for Dog" << RESET << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog &other)
{
    std::cout << BLACK << "Copy constructor called for Dog" << RESET << std::endl;
    _type = other._type;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << BLACK << "Assignment operator called for Dog" << RESET << std::endl;
    if (this != &other)
    {
        _type = other._type;
        delete _brain; // Free the old brain
        _brain = new Brain(*other._brain); // Create a new brain
    }
    return *this;
}

Dog::~Dog()
{
    delete _brain; // Free the brain
    std::cout << BLACK << "Destructor called for Dog" << RESET << std::endl;
}

void Dog::makeSound() const
{
    std::cout << this->_type << ": Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return _brain;
}