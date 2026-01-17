#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name){}

void Zombie::announce(void)
{
    std::cout << getName() << ": BraiiiiiiinnnzzzZ...\n";
}

std::string Zombie::getName(void)
{
    return (name);
}

Zombie::~Zombie()
{
    std::cout << name << " Destroyed!\n";
}