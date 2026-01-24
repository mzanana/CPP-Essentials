#include "Cat.hpp"


Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat Default Constructor Called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy Constructor Called\n";
}

Cat& Cat::operator=(const Cat& right)
{
	std::cout << "Cat Copy Assignment Operator Called\n";
	Animal::operator=(right);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called\n";
}

void Cat::makeSound(void) const
{
	std::cout << "The cat meows\n";
}
