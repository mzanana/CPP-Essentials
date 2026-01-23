#include "FragTrap.hpp"

int main()
{
    FragTrap kibe("Kibe");

    std::cout << std::endl;
    kibe.attack("Freg");

    std::cout << std::endl;
    kibe.takeDamage(99);

    std::cout << std::endl;
    kibe.beRepaired(100);

    std::cout << std::endl;
    kibe.highFivesGuys();

    std::cout << std::endl;

    return 0;
}