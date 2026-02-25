#include "easyfind.hpp"
int main()
{
	std::vector<int> vec;

	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(-9);
	vec.push_back(0);
	vec.push_back(1);
	
	try
	{
		std::vector<int>::iterator it = easyfind(vec, -9);
		std::cout << *it << std::endl;
		it = easyfind(vec, 1337);
		std::cout << *it << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}
	std::cout << "******************\nThe Program Exit Successfully!\n";
}