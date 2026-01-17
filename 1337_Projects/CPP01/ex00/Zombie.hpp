#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        std::string getName(void);
        void announce(void);
        Zombie(std::string name) : name(name) {};
        ~Zombie()
        {
            std::cout << this->name << " Destroyed!\n";
        };
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif