#include "Zombie.hpp"

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );

int main()
{
    std::cout << YELLOW << "++++++++++++++++++++++++++++++++++++++++++++++++++" << RESET << std::endl;
    std::cout << "Zombie is creating on the stack" << std::endl;
    Zombie  Zombie1 = Zombie("Zombie1");
    Zombie1.announce();

    std::cout << YELLOW << "++++++++++++++++++++++++++++++++++++++++++++++++++" << RESET << std::endl;
    std::cout << "Zombie is creating on the heap" << std::endl;
    Zombie  *Zombie2 = newZombie("Zombie2");
    Zombie2->announce();
    std::cout << "Zombie is deleting" << std::endl;
    delete Zombie2;

    std::cout << YELLOW << "++++++++++++++++++++++++++++++++++++++++++++++++++" << RESET << std::endl;
    std::cout << "Zombie is creating and announcing via randomChump()" << std::endl;
    randomChump("Zombie3");
}
