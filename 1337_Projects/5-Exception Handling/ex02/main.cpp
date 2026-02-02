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
		{
			Bureaucrat simo("simo", 1);
			ShrubberyCreationForm tree("darna");
			simo.signForm(tree);
			simo.executeForm(tree);		
		}
		{
			std::cout << std::endl;
			Bureaucrat simo("simo", 1);
			RobotomyRequestForm radio("radio");
			simo.signForm(radio);
			simo.executeForm(radio);		
		}
		{
			std::cout << std::endl;
			Bureaucrat simo("simo", 1);
			PresidentialPardonForm wifi("wifi");
			simo.signForm(wifi);
			simo.executeForm(wifi);		
		}
		{
			std::cout << std::endl;
			Bureaucrat simo("simo", 10);
			PresidentialPardonForm wifi("wifi");
			simo.signForm(wifi);
			simo.executeForm(wifi);		
		}
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}
	return (0);
}