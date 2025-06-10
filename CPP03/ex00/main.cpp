#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap1("Antonio");
    ClapTrap claptrap2("Bob");

    std::cout << "+++++++++++++GAME START+++++++++++++" << std::endl;
    std::cout << "\n";
    std::cout << claptrap1.status() << std::endl;
    std::cout << claptrap2.status() << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    claptrap1.attack(claptrap2.getName());
    claptrap2.takeDamage(claptrap1.getAttackDamage());
    claptrap2.beRepaired(3);
    std::cout << "-------------------------------------" << std::endl;
    std::cout << claptrap1.status() << std::endl;
    std::cout << claptrap2.status() << std::endl;
    
    return 0;
}