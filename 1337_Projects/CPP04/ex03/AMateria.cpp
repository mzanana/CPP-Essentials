#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "Default";
}

AMateria::AMateria(std::string const& type) : type(type){}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& right)
{
	if (this != &right)
		this->type = right.type;
	return (*this);
}

AMateria::~AMateria(){}

const std::string& AMateria::getType() const
{
	return (this->type);
}

void AMateria:: use(ICharacter& target)
{
	(void)target;
}
