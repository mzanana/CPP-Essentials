#include "Span.hpp"

int main()
{
	try
	{
		std::vector<int>	multiple(5, 1337);
		Span 				sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.ft_print();
		// sp.multipleAdd(multiple);
		// sp.ft_print();
		// sp.addNumber(11);
		std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span  : " << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}
}
