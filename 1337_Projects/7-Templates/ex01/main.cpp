#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T& element)
{
	std::cout << element << ' ';
}

template <typename T>
void appElement(T& element)
{
	element += element;
}

int main()
{
	int arrayInt[5] = {1, 3, 7, 42, 0};
	std::string arrayStr[3] = {"first", "second", "third"};
	std::cout << "Before : ";
	iter(arrayInt, 5, printElement<int>);
	iter(arrayInt, 5, appElement<int>);
	std::cout << std::endl << "After  : ";
	iter(arrayInt, 5, printElement<int>);
	std::cout << std::endl << "********************" << std::endl << "Before : ";
	iter(arrayStr, 3, printElement<std::string>);
	iter(arrayStr, 3, appElement<std::string>);
	std::cout << std::endl << "After  : ";
	iter(arrayStr, 3, printElement<std::string>);
}
