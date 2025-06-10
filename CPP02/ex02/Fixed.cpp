#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << BLACK << "Default constructor called" << RESET << std::endl;
    _fixedPointValue = 0;
}

Fixed::Fixed( int const value )
{
    // std::cout << BLACK << "Int constructor called" << RESET << std::endl;
    _fixedPointValue = value * powf(2, _fractionalBits);
}

Fixed::Fixed( float const value )
{
    // std::cout << BLACK << "Float constructor called" << RESET << std::endl;
    _fixedPointValue = roundf(value * powf(2, _fractionalBits));
}

Fixed::Fixed( const Fixed &src )
{
    // std::cout << BLACK << "Copy constructor called" << RESET << std::endl;
    *this = src;
}

Fixed& Fixed::operator=( const Fixed &rhs )
{
    // std::cout << BLACK << "Copy assignment operator called" << RESET << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << BLACK << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits( void ) const
{
    // std::cout << BLACK << "getRawBits member function called" << RESET << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits member function called" << std::endl;
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

bool Fixed::operator>( const Fixed& rhs ) const
{
    if (this->_fixedPointValue > rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<( const Fixed& rhs )  const
{
    if (this->_fixedPointValue < rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=( const Fixed& rhs ) const
{
    if (this->_fixedPointValue >= rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=( const Fixed& rhs ) const
{
    if (this->_fixedPointValue <= rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator==( const Fixed& rhs ) const
{
    if (this->_fixedPointValue == rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=( const Fixed& rhs ) const
{
    if (this->_fixedPointValue != rhs.getRawBits())
        return true;
    return false;
}

Fixed Fixed::operator+( const Fixed& rhs ) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-( const Fixed& rhs ) const
{
    Fixed result;
    result._fixedPointValue = this->_fixedPointValue - rhs._fixedPointValue;
    return result;
}

Fixed Fixed::operator*( const Fixed& rhs ) const
{
    Fixed result;
    result._fixedPointValue = (this->_fixedPointValue * rhs.getRawBits());
    result._fixedPointValue >>= _fractionalBits;
    return result;
}

Fixed Fixed::operator/( const Fixed& rhs ) const
{
    Fixed result;
    if (rhs.getRawBits() == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return result;
    }
    result.setRawBits(this->_fixedPointValue / rhs.getRawBits());
    return result;
}

Fixed& Fixed::operator++( void ) // prefix
{
    this->_fixedPointValue++;
    return *this;
}

Fixed  Fixed::operator++( int ) // postfix
{
    Fixed temp = *this;
    this->_fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--( void )
{
    this->_fixedPointValue--;
    return *this;
}

Fixed  Fixed::operator--( int )
{
    Fixed temp = *this;
    this->_fixedPointValue--;
    return temp;
}

Fixed& Fixed::min( Fixed& a, Fixed& b )
{
    if (a < b)
        return a;
    return b;
}

// static const Fixed& Fixed::min( const Fixed& a, const Fixed& b ){}
Fixed& Fixed::max( Fixed& a, Fixed& b )
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b )
{
    if (a > b)
        return a;
    return b;
}
