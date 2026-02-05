#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& right)
{
	(void)right;
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

AForm* Intern::makeForm(const std::string& formName, const std::string&target)
{
	int i;

	std::string forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm*(Intern::*retFun[])(std::string) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};
	i = 0;
	while (i < 3)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*retFun[i])(target);
		}
		i++;
	
	}
	std::cout << "Intern cannot find " << formName << " form on the desk!!\n";
	return (NULL);
}