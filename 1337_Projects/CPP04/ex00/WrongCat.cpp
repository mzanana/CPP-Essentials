#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat Default Constructor Called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy Constructor Called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& right)
{
	std::cout << "WrongCat Copy Assignment Operator Called\n";
	WrongAnimal::operator=(right);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called\n";
}

void WrongCat::makeSound(void) const
{
	std::cout << "The WrongCat meows\n";
}
