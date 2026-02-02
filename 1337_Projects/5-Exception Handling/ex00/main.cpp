#include "Bureaucrat.hpp"

int main()
{
	try
	{
		{	// Normal grade 
			Bureaucrat bur("simo", 3);
			std::cout << "Before : " << bur;
			bur.incGrade();
			std::cout << "After  : " << bur;
		}
	
		{	// Lower grade
			Bureaucrat bur("simo", 151);
			std::cout << "Before : " << bur;
			bur.decGrade();
			std::cout << "After  : " << bur;
		}	
	}
	catch(std::exception e)
	{
		std::cout << e.what();
	}
	try
	{
		{	// Higher grade
			Bureaucrat bur("simo", 0);
			std::cout << "Before : " << bur;
			bur.decGrade();
			std::cout << "After  : " << bur;
		}
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}
}