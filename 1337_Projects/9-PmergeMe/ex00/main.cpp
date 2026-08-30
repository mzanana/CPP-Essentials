#include "BitcoinExchange.hpp"
#include <iostream>


int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Invalid Argument" << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange btc("data.csv");

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
} 	