#include "Zombie.hpp"

int main()
{
    Zombie *zomHeap = newZombie("heap");

    zomHeap->announce();
    randomChump("Stacker");
    delete zomHeap;
}