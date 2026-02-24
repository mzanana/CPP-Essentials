#include "Span.hpp"

int main()
{
	{// normal test like the one on the subject
		try
		{
			Span	sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			// sp.ft_print();
			// sp.addNumber(11);
			std::cout << "******Normal test******\n";
			std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span  : " << sp.longestSpan() << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << e.what();
		}
	}


	{ // test 10000 number
		try
		{
        	Span large(10000);
        	for (int i = 0; i < 10000; i++)
            	large.addNumber(i);
			std::cout << "\n******10000 test******\n";
        	std::cout << "Large Shortest: " << large.shortestSpan() << std::endl;
        	std::cout << "Large Longest: " << large.longestSpan() << std::endl;
    	}
		catch(std::exception& e)
		{
        	std::cout << e.what();
		}
	}

	{// multipleAdd method
		try
		{
			Span sp2(10);
			std::vector<int> range;

			for (int i = 0; i < 8; i++)
				range.push_back(i * 2);
			sp2.multipleAdd(range);
			// std::cout << "\n******Multiple test******\n";
			// sp2.ft_print();
		}
		catch(std::exception& e)
		{
			std::cout << e.what();
		}
	}
}
