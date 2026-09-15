#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	(void)av;
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange btc("data.csv");
		btc.EvaluateInput(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
} 	