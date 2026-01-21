#include "Fixed.hpp"

Fixed::Fixed():value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& right)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &right)
		this->value = right.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

void Fixed::setRawBits(int raw)
{
	this->value = raw;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}
