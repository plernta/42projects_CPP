#include "Harl.hpp"

void Harl::debug( void ) const
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) const
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) const
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month" << std::endl;
}

void Harl::error( void ) const
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
    std::cout << BLACK << "Harl constructor called" << RESET << std::endl;
}

Harl::~Harl()
{
    std::cout << BLACK << "Harl destructor called" << RESET << std::endl;
}

void Harl::complain( std::string level )
{
    void (Harl::*functions[4])(void) const = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

    while (i < 4)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            break;
        }
        i++;
    }
}