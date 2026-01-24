#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Default Constructor Called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy Constructor Called\n";
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& right)
{
	std::cout << "Dog Copy Assignment Operator Called\n";
	if (this != &right)
	{
		Animal::operator=(right);
		delete brain;
		brain = new Brain(*right.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor Called\n";
}

void Dog::makeSound(void) const
{
	std::cout << "The dog barks\n";
}
