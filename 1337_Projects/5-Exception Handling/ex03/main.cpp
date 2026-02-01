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
		AForm* chajara = messi.makeForm("ShrubberyCreation", "chajara");
		simo.signForm(*chajara);
		simo.executeForm(*chajara);
	}
	{
		Bureaucrat simo("simo", 1);
		Intern messi;
		messi.makeForm("ShrubberyCreation", "chajara");	
	}
		return (0);
}