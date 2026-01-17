#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name){}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

std::string Zombie::getName(void)
{
    return (this->name);
}

Zombie::~Zombie()
{
    std::cout << this->name << " Destroyed!\n";
}

void Zombie::setName(std::string name) 
{
   this->name = name;
}