#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other){}

Intern& Intern::operator=(const Intern& right)
{
	return (*this);
}

Intern::~Intern(){}

AForm* Intern::makeShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	
}