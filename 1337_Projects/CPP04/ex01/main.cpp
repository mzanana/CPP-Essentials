#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    int arraySize = 20;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
	std::cout << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        delete animals[i];
    }
	std::cout << std::endl << std::endl << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }
	std::cout << std::endl;
    return 0;
}