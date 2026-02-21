#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	int size = 10;
	Array<int> first(size);
	
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		int value = std::rand() % 10;
		first[i] = value;
		std::cout << first[i] << " ";
	}
	std::cout << std::endl;

	Array<int> tmp = first;
	for (int i = 0; i < size; i++)
	{
		std::cout << tmp[i] << " ";
	}
	std::cout << std::endl;

	Array<int> second(tmp);
	for (int i = 0; i < size; i++)
	{
		std::cout << second[i] << " ";
	}
	std::cout << std::endl;


	try
	{
		second[size] = 1;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		second[-size] = 1;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Exiting program successfuly!" << std::endl;
	return (0);
}