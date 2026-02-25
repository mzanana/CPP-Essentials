#include "Span.hpp"

Span::Span() : N(0){}

Span::Span(unsigned int size): N(size){}

Span::Span(const Span& other) : N(other.N), vec(other.vec){}

Span& Span::operator=(const Span& right)
{
	if (this != &right)
	{
		N = right.N;
		vec = right.vec;
	}
	return (*this);
}

Span::~Span(){}

const char* Span::AddErrorException::what() const throw()
{
	return ("No space to add new number(s)!\n");
}

const char* Span::NoSpanException:: what() const throw()
{
	return ("Make sure you entred at least two numbers!\n");
}

void Span::addNumber(int toAdd)
{
	if (vec.size() == N)
		throw AddErrorException();
	vec.push_back(toAdd);
}

int Span::shortestSpan()
{
	if (vec.size() < 2)
		throw NoSpanException();
	
	int shortest;
	int tmpInt;
	std::vector<int> tmpVec;
	
	tmpVec = vec;
	sort(tmpVec.begin(), tmpVec.end());
	shortest = tmpVec[1] - tmpVec[0];
	for (size_t i = 1; i < tmpVec.size() - 1; i++)
	{
		tmpInt = tmpVec[i + 1] - tmpVec[i];
		if (tmpInt < shortest)
			shortest = tmpInt;
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (vec.size() < 2)
		throw NoSpanException();

	std::vector<int> tmpVec;

	tmpVec = vec;
	sort(tmpVec.begin(), tmpVec.end());
	return (tmpVec[tmpVec.size() - 1] - tmpVec[0]);
}

void Span::multipleAdd(const std::vector<int>& numbers)
{
	if (vec.size() + numbers.size() > N)
		throw AddErrorException();
	vec.insert(vec.end(), numbers.begin(), numbers.end());
}

// void Span::ft_print()
// {
// 	for (iter it = vec.begin(); it != vec.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << std::endl;
// }
