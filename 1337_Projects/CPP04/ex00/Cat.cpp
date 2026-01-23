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

Cat::Cat (const std::string& name) : Animal("Cat"), name(name)
{
	std::cout << "Cat Parameterized Constructor Called\n";
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called\n";
}

void Cat::setType(const std::string& type)
{
	this->type = type;

}

void Cat::makeSound(void) const
{
	std::cout << "The Cat " << name <<  " meows\n";
}
