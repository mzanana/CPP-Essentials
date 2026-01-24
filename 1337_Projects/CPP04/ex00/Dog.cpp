#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor Called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy Constructor Called\n";
}

Dog& Dog::operator=(const Dog& right)
{
	std::cout << "Dog Copy Assignment Operator Called\n";
	Animal::operator=(right);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called\n";
}

void Dog::makeSound(void) const
{
	std::cout << "The dog barks\n";
}
