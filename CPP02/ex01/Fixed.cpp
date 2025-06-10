#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << BLACK << "Default constructor called" << RESET << std::endl;
    _fixedPointValue = 0;
}

Fixed::Fixed( int const value )
{
    std::cout << BLACK << "Int constructor called" << RESET << std::endl;
    _fixedPointValue = value * powf(2, _fractionalBits);
}

Fixed::Fixed( float const value )
{
    std::cout << BLACK << "Float constructor called" << RESET << std::endl;
    _fixedPointValue = roundf(value * powf(2, _fractionalBits));
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
    std::cout << BLACK << "getRawBits member function called" << RESET << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
    return (_fixedPointValue >> _fractionalBits);
}

std::ostream& operator<<( std::ostream &os, const Fixed& src )
{
    os << src.toFloat();
    return os;
}