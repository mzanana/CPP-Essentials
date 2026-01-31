#include "Bureaucrat.hpp"

int main()
{
	{	// Normal output 
		Bureaucrat bur("simo", 3);
		std::cout << "Before : " << bur;
		bur.decGrade();
		std::cout << "After  : " << bur;
	}
	
	{  //Grade Too Low Exception
		std::cout << std::endl;	
		try
		{	
			Bureaucrat bur("simo", 151);
			std::cout << "Before : " << bur;
			bur.decGrade();
			std::cout << "After  : " << bur;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what();
		}
	}
	
	{  //Grade Too High Exception
		try
		{
			Bureaucrat bur("simo", 0);
			std::cout << "Before : " << bur;
			bur.decGrade();
			std::cout << "After  : " << bur;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what();
		}
	}
}