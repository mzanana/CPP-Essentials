// #include "Bureaucrat.hpp"
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
		
		{// normal test
			Form resid("chahadat sokna", 75, 75);
			Bureaucrat kayd("da7mad", 50);
			kayd.signForm(resid);
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