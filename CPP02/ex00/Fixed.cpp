#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << BLACK << "Default constructor called" << RESET << std::endl;
    _fixedPointValue = 0;
}

Fixed::Fixed( const Fixed &src )
{
    std::cout << BLACK << "Copy constructor called" << RESET << std::endl;
    *this = src;
}

Fixed& Fixed::operator=( const Fixed &rhs )
{
    std::cout << BLACK << "Copy assignment operator called" << RESET << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << BLACK << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}