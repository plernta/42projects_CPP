#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap claptrap1("Antonio");
    ClapTrap claptrap2("Bob");
    ScavTrap scavtrap3("Carol");
    FragTrap fragtrap4("David");

    std::cout << "+++++++++++++GAME START+++++++++++++" << std::endl;
    std::cout << "\n";
    std::cout << claptrap1.status() << std::endl;
    std::cout << claptrap2.status() << std::endl;
    std::cout << scavtrap3.status() << std::endl;
    std::cout << fragtrap4.status() << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    claptrap1.attack(claptrap2.getName());
    claptrap2.takeDamage(claptrap1.getAttackDamage());
    claptrap2.beRepaired(3);
    scavtrap3.attack(claptrap2.getName());
    claptrap2.takeDamage(scavtrap3.getAttackDamage());
    fragtrap4.attack(scavtrap3.getName());
    scavtrap3.takeDamage(fragtrap4.getAttackDamage());
    fragtrap4.highFivesGuys();
    scavtrap3.guardGate();
    std::cout << "-------------------------------------" << std::endl;
    std::cout << claptrap1.status() << std::endl;
    std::cout << claptrap2.status() << std::endl;
    std::cout << scavtrap3.status() << std::endl;
    std::cout << fragtrap4.status() << std::endl;
    
    return 0;
}