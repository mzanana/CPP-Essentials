#include "ClapTrap.hpp"
int main()
{
    ClapTrap kibe("Kibe");
    ClapTrap freg("Freg");

    std::cout << std::endl;
    kibe.attack("Freg");

    std::cout << std::endl;
    freg.takeDamage(10);

    std::cout << std::endl;
    freg.beRepaired(10);

    return 0;
}