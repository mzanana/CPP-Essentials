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

Dog::Dog (const std::string& name) : Animal("Dog"), name(name)
{
	std::cout << "Dog Parameterized Constructor Called\n";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called\n";
}

void Dog::makeSound(void) const
{
	std::cout << "The dog " << name <<  " barks\n";
}
