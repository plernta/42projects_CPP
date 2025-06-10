#include "Cat.hpp"

Cat::Cat()
{
    std::cout << BLACK << "Default constructor called for Cat" << RESET << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat &other)
{
    std::cout << BLACK << "Copy constructor called for Cat" << RESET << std::endl;
    _type = other._type;
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << BLACK << "Assignment operator called for Cat" << RESET << std::endl;
    if (this != &other)
    {
        _type = other._type;
        delete _brain; // Free the old brain
        _brain = new Brain(*other._brain); // Create a new brain
    }
    return *this;
}

Cat::~Cat()
{
    delete this->_brain; // Free the brain
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