#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // Animal *animal = new Animal;
    Dog *dog = new Dog();
    dog->makeSound();
	std::cout << std::endl;
    delete dog;
}