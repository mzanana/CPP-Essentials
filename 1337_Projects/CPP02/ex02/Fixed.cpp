#include "Fixed.hpp"

Fixed::Fixed():value(0){}

Fixed::Fixed(const int x)
{
	value = x << fraction;
}

Fixed::Fixed(const float y)
{
	value = roundf(y * (1 << fraction));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& right)
{
	if (this != &right)
		this->value = right.getRawBits();
	return (*this);
}

Fixed::~Fixed(){}

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





Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed ret;

	ret.setRawBits(this->value + other.value);
	return (ret);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed ret;

	ret.setRawBits(this->value - other.value);
	return (ret);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed ret;
	
	ret.setRawBits((long(this->value) * long(other.value)) >> fraction);
	return (ret);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed ret;

	ret.setRawBits((long(this->value) << fraction) / other.value);
	return (ret);
}






bool Fixed::operator>(const Fixed& other) const
{
	return (this->value > other.value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->value < other.value);
}
bool Fixed::operator>=(const Fixed& other) const
{
	return (this->value >= other.value);
}
bool Fixed::operator<=(const Fixed& other) const
{
	return (this->value <= other.value);
}
bool Fixed::operator==(const Fixed& other) const
{
	return (this->value == other.value);
}
bool Fixed::operator!=(const Fixed& other) const
{
	return (this->value != other.value);
}


Fixed& Fixed::operator++()
{
	this->value++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed copy(*this);

	this->value++;
	return copy;
}
Fixed& Fixed::operator--()
{
	this->value--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed copy(*this);

	this->value--;
	return (copy);
}



Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}