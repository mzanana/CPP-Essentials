#include "Zombie.hpp"

Zombie::Zombie(){}

std::string Zombie::getName(void)
{
    return (this->name);
}

void Zombie::announce(void)
{
    std::cout << getName() << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
    std::cout << this->name << " Destroyed!\n";
}

void Zombie::setName(std::string name) 
{
   this->name = name;
}
