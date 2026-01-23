#include "ScavTrap.hpp"

int main()
{
    ScavTrap kibe("Kibe");
    ScavTrap freg("Freg");

    std::cout << std::endl;
    kibe.attack("Freg");

    std::cout << std::endl;
    freg.takeDamage(200);

    std::cout << std::endl;
    freg.beRepaired(10);

    std::cout << std::endl;
    freg.guardGate();

    std::cout << std::endl;

    return 0;
}