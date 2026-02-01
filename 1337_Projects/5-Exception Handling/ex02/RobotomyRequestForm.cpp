#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45){
	target = "Default Target";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequest", 72, 45), target(target){}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :  AForm(other), target(other.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& right)
{
	if (this != &right)
	{
		AForm::operator=(right);
		this->target = right.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (target);
}

void RobotomyRequestForm::action() const
{
    std::cout << "hkajshfkahdffhdahfkhdfa\n";
    // std::srand(std::time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << target << " has bee robotomized successfully\n";
    else
        std::cout << "robotomy failed\n";
}

