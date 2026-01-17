#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

std::string Zombie::getName(void)
{
    return (this->name);
}
