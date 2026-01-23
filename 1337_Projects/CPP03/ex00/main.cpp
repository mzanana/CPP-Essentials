#include "ClapTrap.hpp"
int main()
{
    ClapTrap kibe("Kibe");
    ClapTrap freg("Freg");

    kibe.attack("Freg");
    freg.takeDamage(0);

    kibe.takeDamage(5);
    kibe.beRepaired(3);

    for (int i = 0; i < 10; i++)
        freg.attack("target");
    
    freg.attack("target");
    freg.beRepaired(5);

    kibe.takeDamage(20);
    kibe.attack("Freg");
    kibe.beRepaired(5);

    return 0;
}