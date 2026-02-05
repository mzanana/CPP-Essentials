#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5){
	target = "Default Target";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :  AForm("PresidentialPardon", 25, 5), target(target){}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :  AForm(other), target(other.target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& right)
{
	if (this != &right)
	{
		AForm::operator=(right);
		this->target = right.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (target);
}

void PresidentialPardonForm::action() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}

