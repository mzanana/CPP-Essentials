#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat Default Constructor Called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy Constructor Called\n";
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& right)
{
	std::cout << "Cat Copy Assignment Operator Called\n";
	if (this != &right)
	{
		Animal::operator=(right);
		delete brain;
		brain = new Brain(*right.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destructor Called\n";
}

void Cat::makeSound(void) const
{
	std::cout << "The cat meows\n";
}
