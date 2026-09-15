#include "RPN.hpp"

int main(int ac, char**av)
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	try
	{
		RPN rpn;
		std::cout << rpn.execute(av[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}

	return (0);
}