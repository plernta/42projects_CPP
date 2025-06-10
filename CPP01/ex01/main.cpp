#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string names[] );

int main()
{
    int N = 5;
    int i = 0;

    std::string names[5] = {"Alice", "Bob", "Charlie", "Dave", "Eve"};


    std::cout << "Creating zombie horde..." << std::endl;
    Zombie *horde = zombieHorde( N, names);
    std::cout << "++++++++++++++++++++++++++++++" << std::endl;
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    std::cout << "++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "Deleting zombie horde..." << std::endl;
    delete[] horde;
}