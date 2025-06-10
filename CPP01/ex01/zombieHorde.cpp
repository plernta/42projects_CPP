#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string names[] )
{
    int i = 0;
    Zombie *horde = new Zombie[N];
    while (i < N)
    {
        horde[i].setName(names[i]);
        i++;
    }
    return horde;
}
