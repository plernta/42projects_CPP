#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

#define BLACK "\033[30m"
#define RESET "\033[0m"
class Fixed
{
    private: 
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
    public:
        Fixed();
        Fixed( int const value );
        Fixed( float const value );
        Fixed( const Fixed &src );
        Fixed& operator=( const Fixed& rhs );
        ~Fixed();
        
        bool operator>( const Fixed& rhs ) const;
        bool operator<( const Fixed& rhs )  const;
        bool operator>=( const Fixed& rhs ) const;
        bool operator<=( const Fixed& rhs ) const;
        bool operator==( const Fixed& rhs ) const;
        bool operator!=( const Fixed& rhs ) const;

        Fixed operator+( const Fixed& rhs ) const;
        Fixed operator-( const Fixed& rhs ) const;
        Fixed operator*( const Fixed& rhs ) const;
        Fixed operator/( const Fixed& rhs ) const;

        Fixed& operator++( void ); // prefix
        Fixed  operator++( int ); // postfix
        Fixed& operator--( void ); // prefix
        Fixed  operator--( int ); // postfix

        static Fixed& min( Fixed& a, Fixed& b );
        // static const Fixed& min( const Fixed& a, const Fixed& b );
        static Fixed& max( Fixed& a, Fixed& b );
        static const Fixed& max( const Fixed& a, const Fixed& b );

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};
    
    std::ostream& operator<<( std::ostream &os, const Fixed& src );

#endif