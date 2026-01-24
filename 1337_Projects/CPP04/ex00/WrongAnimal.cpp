#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("!   WrongAnimal  !")
{
	std::cout << "WrongAnimal Default Constructor Called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Copy Constructor Called\n";
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& right)
{
	std::cout << "WrongAnimal Copy Assignment Operator Called\n";
	if (this != &right)
		this->type = right.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor Called\n";
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal Sound\n";
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}