#ifndef EASYFIND_HPP 
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <vector>
#include <iostream>

class ExceptionNotFound : public std::exception
{
	const char* what() const throw()
	{
		return ("Element Not Found!\n");
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int toFind)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw ExceptionNotFound();
	return (it);
}

#endif