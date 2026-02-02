// #include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <unistd.h>
#include "Intern.hpp"

int main()
{
	{
		Bureaucrat simo("simo", 1);
		Intern messi;
		AForm* chajara = messi.makeForm("shrubbery creation", "chajara");
		if (!chajara)
			return (1);
		simo.signForm(*chajara);
		simo.executeForm(*chajara);
	}
	{
		std::cout << std::endl;
		Bureaucrat simo("simo", 10);
		Intern messi;
		AForm* radio = messi.makeForm("robotomy request", "radio");
		if (!radio)
			return (1);
		simo.signForm(*radio);
		simo.executeForm(*radio);
	}
	return (0);
}