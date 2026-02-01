// #include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <unistd.h>

int main()
{
	try
	{
		Bureaucrat simo("simo", 1);
		RobotomyRequestForm tree("darna");
		simo.signForm(tree);
		simo.executeForm(tree);		
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}
	return (0);
}