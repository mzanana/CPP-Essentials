#include "Zombie.hpp"

int main()
{
    int i = 0;
    int N = 3;
    Zombie *zomHeap = zombieHorde(N, "heap");

    while (i < N)
        zomHeap[i++].announce();
    delete[] zomHeap;
}
