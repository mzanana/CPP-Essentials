#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType();


	std::cout << std::endl << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << std::endl;
	delete meta;
	delete i;
	delete j;




	// const WrongAnimal* meta = new WrongAnimal();
	// const WrongAnimal* i = new WrongCat();
	// std::cout << std::endl << std::endl;
	// std::cout << i->getType();


	// std::cout << std::endl << std::endl;
	// i->makeSound(); //will output the cat sound!
	// meta->makeSound();

	// std::cout << std::endl << std::endl;
	// delete meta;
	// delete i;
}