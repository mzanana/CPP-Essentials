#include "Form.hpp"

int main()
{
	try
	{
		{// bureaucrat failed test
			Form resid("chahadat sokna", 75, 700);
			Bureaucrat kayd("da7mad", 70);
			std::cout << resid;
			kayd.signForm(resid);
			std::cout << resid << std::endl << std::endl;
		}
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		{// normal test
			Form resid("chahadat sokna", 75, 75);
			std::cout << resid;
			Bureaucrat kayd("da7mad", 75);
			kayd.signForm(resid);
			std::cout << resid;
		}
		
		{// lower grade test
			Form resid("chahadat sokna", 75, 75);
			Bureaucrat kayd("da7mad", 80);
			kayd.signForm(resid);
		}
	}	
	catch(std::exception& e)
	{
		std::cout << e.what();
	}
}