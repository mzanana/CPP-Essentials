#include "Bureaucrat.hpp"

int main()
{
	{	// Normal output 
		Bureaucrat bur("simo", 3);
		std::cout << "Before : " << bur << std::endl;
		bur.decGrade();
		std::cout << "After  : " << bur << std::endl << std::endl;
	}
	
	{  //Grade Too Low Exception
		try
		{	
			Bureaucrat bur("simo", 151);
			std::cout << "Before : " << bur << std::endl;
			bur.decGrade();
			std::cout << "After  : " << bur << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what();
		}
	}

	{  //Grade Too High Exception
		try
		{
			std::cout << std::endl;	
			Bureaucrat bur("simo", 0);
			std::cout << "Before : " << bur << std::endl;
			bur.decGrade();
			std::cout << "After  : " << bur << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what();
		}
	}
}