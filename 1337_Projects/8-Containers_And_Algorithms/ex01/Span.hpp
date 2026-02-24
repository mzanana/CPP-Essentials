#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>
#include <iostream>
#include <algorithm>

typedef std::vector<int>::iterator iter;

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	vec;
	public:
		Span();
		Span(unsigned int size);
		Span(const Span& other);
		Span& operator=(const Span& right);
		~Span();
		
		class AddErrorException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				const char*what() const throw();
		};

		void addNumber(int toAdd);
		int shortestSpan();
		int longestSpan();
		void multipleAdd(const std::vector<int>& numbers);
		// void ft_print();
};

#endif