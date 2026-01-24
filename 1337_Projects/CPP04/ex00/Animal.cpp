#include "Animal.hpp"


Animal::Animal() : type("!   Uknown Animal  !")
{
	std::cout << "Animal Default Constructor Called\n";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal Copy Constructor Called\n";
	*this = other;
}

Animal& Animal::operator=(const Animal& right)
{
	std::cout << "Animal Copy Assignment Operator Called\n";
	if (this != &right)
		this->type = right.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called\n";
}

void Animal::makeSound(void) const
{
	std::cout << "Animal Sound\n";
}

std::string Animal::getType(void) const
{
	return (this->type);
}