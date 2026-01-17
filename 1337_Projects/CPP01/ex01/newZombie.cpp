#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *ret = new Zombie(name);
    return (ret);
}
Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombies = new Zombie[N];
    return (zombies);
}
