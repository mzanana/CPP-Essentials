#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		{// bureaucrat failed test
			Form resid("chahadat sokna", 75, 75);
			Bureaucrat kayd("da7mad", 70);
			kayd.signForm(resid);
		}

		{// normal test
			Form resid("chahadat sokna", 75, 75);
			Bureaucrat kayd("da7mad", 50);
			std::cout << resid.getIsSigned() << std::endl;
			kayd.signForm(resid);
			std::cout << resid.getIsSigned() << std::endl;
		}

		{// lower grade test
			Form resid("chahadat sokna", 75, 75);
			Bureaucrat kayd("da7mad", 80);
			std::cout << resid.getIsSigned() << std::endl;
			kayd.signForm(resid);
			std::cout << resid.getIsSigned() << std::endl;
		}
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}
}