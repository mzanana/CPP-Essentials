#include "Fixed.hpp"

Fixed::Fixed():value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called\n";
	value = x << fraction;
}

Fixed::Fixed(const float y)
{
	std::cout << "Float constructor called\n";
	value = roundf(y * (1 << fraction));
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
	return (this->value);
}

std::ostream& operator<<(std::ostream& right, const Fixed& number)
{
	right << number.toFloat();
	return (right);
}

int Fixed::toInt() const
{
	return (value >> fraction);
}

float Fixed::toFloat() const
{
	return (float(value) / (1 << fraction));
}